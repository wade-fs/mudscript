// daemon/quest_engine_d.c
// 《遺忘的世界》抽象化任務引擎守護進程 (QUEST_ENGINE_D)
// 支援基於 /quests/*.json 的宣告式狀態機、信物遺失自動補領與結構化進度追蹤

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/object.c";

mapping quest_defs;

void load_all_quests();

void create() {
    ::create();
    quest_defs = ([]);
    load_all_quests();
}

// 載入指定 JSON 檔案並加入任務池
int load_quest_file(string path) {
    string content = read_file(path);
    if (!content || content == "") return 0;

    mixed def = json_decode(content);
    if (!mapp(def) || !def["id"]) {
        return 0;
    }

    quest_defs[def["id"]] = def;
    return 1;
}

// 掃描 /quests/ 目錄下的所有 JSON 任務定義檔
void load_all_quests() {
    quest_defs = ([]);

    // 優先動態掃描 /quests/ 目錄
    string *files = get_dir("/quests/", 1);
    if (arrayp(files) && sizeof(files) > 0) {
        foreach (string f in files) {
            if (strlen(f) > 5 && substr(f, strlen(f) - 5, 5) == ".json") {
                load_quest_file("/quests/" + f);
            }
        }
    }

    // 備援載入清單，確保跨環境穩定
    string *fallback = ({
        "/quests/career/wu_chain.json",
        "/quests/career/li_chain.json",
        "/quests/career/fa_chain.json",
        "/quests/side/wolf_hunter.json",
        "/quests/main/village_pass.json"
    });

    foreach (string path in fallback) {
        if (!quest_defs[path]) {
            load_quest_file(path);
        }
    }
}

mapping query_quest(string qid) {
    return quest_defs[qid];
}

mapping query_all_quests() {
    return quest_defs;
}

// ── 玩家進度查詢與狀態同步 ─────────────────────────────────

int query_quest_step(object who, string qid) {
    if (!who || !qid) return 0;
    
    // 優先檢查道統任務相容路徑
    mapping q = quest_defs[qid];
    if (q && q["path_type"]) {
        return who->query("task_chain/" + q["path_type"] + "_stage");
    }

    return who->query("quests/" + qid + "/step");
}

void set_quest_step(object who, string qid, int step) {
    if (!who || !qid) return;

    mapping q = quest_defs[qid];
    if (q && q["path_type"]) {
        who->set("task_chain/" + q["path_type"] + "_stage", step);
    }
    who->set("quests/" + qid + "/step", step);
}

int query_quest_rounds(object who, string qid) {
    if (!who || !qid) return 0;
    mapping q = quest_defs[qid];
    if (q && q["path_type"]) {
        return who->query("task_chain/" + q["path_type"] + "_rounds");
    }
    return who->query("quests/" + qid + "/rounds");
}

// ── 信物檢查與丟失補領判定 ─────────────────────────────────

// 檢查玩家身上是否持有特定信物
int has_required_item(object who, string req) {
    if (!who || !req || req == "") return 1;

    // 1. 直接 present 尋找 id
    if (present(req, who)) return 1;

    // 2. 依型別別名與特徵屬性判斷
    object *inv = all_inventory(who);
    foreach (object ob in inv) {
        if (req == "huoluo_dan" || req == "san") {
            if (ob->id("huoluo san") || ob->id("san") || ob->id("活絡散")) return 1;
        }
        if (req == "herb_dew" || req == "dew_herb") {
            if (ob->query("herb_type") == "dew" || ob->id("dew herb") || ob->id("晨露草")) return 1;
        }
        if (req == "tainted_pelt" || req == "pelt") {
            if (ob->query("is_pelt") || ob->id("tainted pelt") || ob->id("獸皮")) return 1;
        }
        if (req == "ore_chunk" || req == "ore") {
            if (ob->query("is_ore") || ob->id("ore chunk") || ob->id("粗鐵礦")) return 1;
        }
    }
    return 0;
}

// 檢查當前步驟是否有遺失的信物
mapping check_lost_item(object who, string qid) {
    if (!who || !quest_defs[qid]) return 0;
    mapping q = quest_defs[qid];
    int cur_step = query_quest_step(who, qid);
    if (cur_step <= 0) return 0;

    mixed *steps = q["steps"];
    if (!arrayp(steps)) return 0;

    for (int i = 0; i < sizeof(steps); i++) {
        mapping s = steps[i];
        if (s["step"] == cur_step) {
            string req = s["require_item"];
            if (req && req != "" && !has_required_item(who, req)) {
                if (s["lost_item_recovery"]) {
                    return s["lost_item_recovery"];
                }
            }
            break;
        }
    }
    return 0;
}

// 專用信物丟失補領處理器
int check_and_handle_lost_item(object who, string npc_id, string topic) {
    if (!who || !npc_id) return 0;
    foreach (string qid, mapping q in quest_defs) {
        mapping recovery = check_lost_item(who, qid);
        if (recovery && recovery["from_npc"] == npc_id) {
            if (!recovery["ask_topic"] || topic == recovery["ask_topic"] || topic == "任務" || topic == "信物") {
                string reissue_path = recovery["reissue_item"];
                if (reissue_path) {
                    object re_ob = clone_object(reissue_path);
                    if (re_ob) {
                        re_ob->move(who);
                        tell_object(who, HIY "\n" + recovery["dialogue"] + "\n" NOR);
                        tell_object(who, HIG "【你重新獲得了關鍵信物：" + re_ob->query_short() + "！】\n\n" NOR);
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

// ── 事件觸發與推進器 (Event Dispatcher) ─────────────────────

mixed trigger_event(object who, string event_type, mapping data) {
    if (!who || !mapp(data)) return 0;

    string npc_id = data["npc"];
    string topic  = data["topic"];
    object item   = data["item"];
    string verb   = data["verb"];
    string target = data["target"];

    foreach (string qid, mapping q in quest_defs) {
        int cur_step = query_quest_step(who, qid);
        mixed *steps = q["steps"];
        if (!arrayp(steps)) continue;

        // 1. 若任務尚未接取 (step == 0)，檢查是否向 start_npc 接取
        if (cur_step == 0) {
            if (event_type == "talk" && npc_id == q["start_npc"] && 
                (!q["start_topic"] || topic == q["start_topic"])) {
                set_quest_step(who, qid, 1);
                tell_object(who, HIG "【接取歷練任務】" + q["name"] + "\n" +
                                     "  目標：" + steps[0]["hint"] + "\n" NOR);
                return 1;
            }
            continue;
        }

        // 2. 檢查信物遺失補領判定 (Lost Item Fallback)
        mapping recovery = check_lost_item(who, qid);
        if (recovery && event_type == "talk") {
            if (npc_id == recovery["from_npc"] && 
                (!recovery["ask_topic"] || topic == recovery["ask_topic"] || topic == "任務" || topic == "信物")) {
                string reissue_path = recovery["reissue_item"];
                if (reissue_path) {
                    object re_ob = clone_object(reissue_path);
                    if (re_ob) {
                        re_ob->move(who);
                        tell_object(who, HIY "\n" + recovery["dialogue"] + "\n" NOR);
                        tell_object(who, HIG "【你重新獲得了關鍵信物：" + re_ob->query_short() + "！】\n\n" NOR);
                        return 1;
                    }
                }
            }
        }

        // 3. 檢查當前步驟是否符合推進條件
        for (int i = 0; i < sizeof(steps); i++) {
            mapping s = steps[i];
            if (s["step"] != cur_step) continue;

            int matched = 0;
            string t_type = s["target_type"];

            if (t_type == "talk" && event_type == "talk") {
                if (npc_id == s["target_npc"] && (!s["target_topic"] || topic == s["target_topic"])) {
                    matched = 1;
                }
            } else if (t_type == "deliver" && event_type == "deliver") {
                if (npc_id == s["target_npc"]) {
                    string req = s["require_item"];
                    if (!req || req == "" || (item && (item->id(req) || item->query("is_" + req) || item->query("herb_type") == req))) {
                        matched = 1;
                    }
                }
            } else if (t_type == "action" && event_type == "action") {
                if (verb == s["action_verb"]) {
                    if (!s["action_target"] || target == s["action_target"]) {
                        matched = 1;
                    }
                }
            }

            if (matched) {
                // 發放步驟完成回饋
                if (s["on_complete"]) {
                    mapping oc = s["on_complete"];
                    if (oc["give_item"]) {
                        object reward_ob = clone_object(oc["give_item"]);
                        if (reward_ob) {
                            reward_ob->move(who);
                            tell_object(who, HIG "【獲得道具：" + reward_ob->query_short() + "】\n" NOR);
                        }
                    }
                    if (oc["msg"]) {
                        tell_object(who, HIG + oc["msg"] + "\n" NOR);
                    }
                }

                // 推進到下一步
                int next_step = cur_step + 1;
                if (next_step > sizeof(steps)) {
                    // 完成整條鏈
                    if (q["type"] == "loop") {
                        set_quest_step(who, qid, 0);
                        int r = query_quest_rounds(who, qid) + 1;
                        if (q["path_type"]) {
                            who->set("task_chain/" + q["path_type"] + "_rounds", r);
                        }
                        who->set("quests/" + qid + "/rounds", r);
                    } else {
                        set_quest_step(who, qid, -1); // -1 代表已終生完成
                    }

                    // 發放終極獎勵
                    if (q["rewards"]) {
                        mapping rw = q["rewards"];
                        if (rw["exp"]) {
                            who->add("exp", rw["exp"]);
                        }
                        if (rw["money"]) {
                            who->add_money(rw["money"]);
                        }
                        if (rw["affinity"]) {
                            mapping aff = rw["affinity"];
                            foreach (string k, int v in aff) {
                                who->add("affinity/" + k, v);
                            }
                        }
                    }

                    tell_object(who, HIY "\n【✨ 恭喜完成歷練：「" + q["name"] + "」！】\n" NOR);
                } else {
                    set_quest_step(who, qid, next_step);
                    tell_object(who, HIG "【任務推進】第 " + sprintf("%d", next_step) + " 步：" + steps[next_step - 1]["hint"] + "\n" NOR);
                }
                return 1;
            }
            break;
        }
    }

    return 0;
}

// ── 結構化任務清單與 Checklist 渲染 ────────────────────────

string query_quest_checklist(object who, string qid) {
    if (!who || !quest_defs[qid]) return "";
    mapping q = quest_defs[qid];
    int cur_step = query_quest_step(who, qid);
    int rounds = query_quest_rounds(who, qid);

    int aff = 0;
    if (q["path_type"]) {
        aff = who->query("affinity/" + q["path_type"]);
    }
    string out = sprintf(HIW "【%s】" NOR " (傳承親和: %d，已完成輪次: %d)\n", q["name"], aff, rounds);
    mixed *steps = q["steps"];
    if (!arrayp(steps)) return out;

    for (int i = 0; i < sizeof(steps); i++) {
        mapping s = steps[i];
        int s_idx = s["step"];
        if (cur_step == 0) {
            out += sprintf(CYN "  [ ] 第 %d 步：%s\n" NOR, s_idx, s["title"]);
        } else if (cur_step > s_idx || cur_step == -1) {
            out += sprintf(HIG "  [✓] 第 %d 步：%s (已完成)\n" NOR, s_idx, s["title"]);
        } else if (cur_step == s_idx) {
            out += sprintf(HIY "  [▶] 第 %d 步：%s (進行中)\n" NOR, s_idx, s["title"]);
            out += sprintf(WHT "      指引：%s\n" NOR, s["hint"]);
            
            // 檢查是否丟失信物
            string req = s["require_item"];
            if (req && req != "" && !has_required_item(who, req)) {
                mapping recovery = s["lost_item_recovery"];
                if (recovery) {
                    out += sprintf(HIR "      ⚠️ 身上缺少關鍵信物，可前往向【%s】詢問「%s」補領！\n" NOR,
                                  recovery["from_npc"], recovery["ask_topic"]);
                } else {
                    out += sprintf(HIR "      ⚠️ 身上缺少關鍵交付物品【%s】！\n" NOR, req);
                }
            }
        } else {
            out += sprintf(GRN "  [ ] 第 %d 步：%s\n" NOR, s_idx, s["title"]);
        }
    }
    return out;
}

// 產生所有任務的總覽面板
string query_all_status_report(object who) {
    if (!who) return "";
    string out = HIW "================ 黑石鋪歷練與任務總覽 ================\n" NOR;
    
    // 依序輸出三大道統鏈
    string *career_chains = ({ "wu_chain", "li_chain", "fa_chain" });
    foreach (string qid in career_chains) {
        if (quest_defs[qid]) {
            out += query_quest_checklist(who, qid) + "\n";
        }
    }

    out += HIW "======================================================\n" NOR;
    return out;
}
