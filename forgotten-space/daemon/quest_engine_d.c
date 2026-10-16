// daemon/quest_engine_d.c
// 《遺忘的世界》抽象化任務引擎守護進程 (QUEST_ENGINE_D)
// 支援基於 /quests/*.json 的跨地圖多階段 (stages) 狀態機、信物遺失自動補領與結構化進度追蹤

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/object.c";

mapping quest_defs;

void load_all_quests();
void handle_stage_completion(object who, string qid, mapping q, int cur_stage);
mapping query_stage_def(mapping q, int stage_num);
mixed *query_stage_steps(mapping q, int stage_num);

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

// 掃描 /quests/ 各子目錄下的所有 JSON 任務定義檔
void load_all_quests() {
    quest_defs = ([]);

    string *subdirs = ({ "", "career/", "main/", "side/", "epic/" });
    foreach (string sub in subdirs) {
        string dir_path = "/quests/" + sub;
        string *files = get_dir(dir_path, 1);
        if (arrayp(files) && sizeof(files) > 0) {
            foreach (string f in files) {
                if (strlen(f) > 5 && substr(f, strlen(f) - 5, 5) == ".json") {
                    load_quest_file(dir_path + f);
                }
            }
        }
    }

    // 備援載入清單，確保跨環境穩定
    string *fallback = ({
        "/quests/career/wu_chain.json",
        "/quests/career/li_chain.json",
        "/quests/career/fa_chain.json",
        "/quests/side/wolf_hunter.json",
        "/quests/main/village_pass.json",
        "/quests/main/cycle_of_craft.json",
        "/quests/main/rescue_maiden.json",
        "/quests/main/rescue_miners.json",
        "/quests/epic/ancient_order.json"
    });

    foreach (string path in fallback) {
        int found = 0;
        foreach (string qid, mapping q in quest_defs) {
            if (q["id"] && strsrch(path, q["id"]) != -1) {
                found = 1;
                break;
            }
        }
        if (!found) {
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

// 取得任務當前 Stage
int query_quest_stage(object who, string qid) {
    if (!who || !qid) return 0;
    mapping q = quest_defs[qid];
    if (q && q["path_type"]) {
        return 1; // 三大道統鏈固定為單階循環
    }
    int st = who->query("quests/" + qid + "/stage");
    return (st > 0) ? st : 1;
}

void set_quest_stage(object who, string qid, int stage) {
    if (!who || !qid) return;
    who->set("quests/" + qid + "/stage", stage);
}

// 取得任務當前 Step
int query_quest_step(object who, string qid) {
    if (!who || !qid) return 0;
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

// 取得任務狀態 ("NOT_STARTED", "ACTIVE", "DORMANT", "COMPLETED")
string query_quest_state(object who, string qid) {
    if (!who || !qid) return "NOT_STARTED";
    mapping q = quest_defs[qid];
    if (q && q["path_type"]) {
        int s = who->query("task_chain/" + q["path_type"] + "_stage");
        return (s > 0) ? "ACTIVE" : "NOT_STARTED";
    }

    int step = who->query("quests/" + qid + "/step");
    if (step == -1) return "COMPLETED";
    if (step == 0) return "NOT_STARTED";

    string st = who->query("quests/" + qid + "/state");
    if (st && st != "") return st;
    return "ACTIVE";
}

void set_quest_state(object who, string qid, string state) {
    if (!who || !qid) return;
    who->set("quests/" + qid + "/state", state);
}

int query_quest_rounds(object who, string qid) {
    if (!who || !qid) return 0;
    mapping q = quest_defs[qid];
    if (q && q["path_type"]) {
        return who->query("task_chain/" + q["path_type"] + "_rounds");
    }
    return who->query("quests/" + qid + "/rounds");
}

// 取得特定 Stage 定義
mapping query_stage_def(mapping q, int stage_num) {
    if (!mapp(q)) return 0;
    if (arrayp(q["stages"]) && sizeof(q["stages"]) > 0) {
        for (int i = 0; i < sizeof(q["stages"]); i++) {
            mapping st = q["stages"][i];
            if (st["stage"] == stage_num) {
                return st;
            }
        }
    }
    return 0;
}

// 取得特定 Stage 下的 steps 陣列
mixed *query_stage_steps(mapping q, int stage_num) {
    if (!mapp(q)) return ({});
    if (arrayp(q["stages"]) && sizeof(q["stages"]) > 0) {
        mapping st = query_stage_def(q, stage_num);
        if (st && arrayp(st["steps"])) {
            return st["steps"];
        }
        return ({});
    }
    return arrayp(q["steps"]) ? q["steps"] : ({});
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
        if (req == "tianmen" || req == "ancient_token" || req == "tianmen_token") {
            if (ob->id("tianmen token") || ob->id("ancient token") || ob->id("token") || ob->id("青金古令") || ob->query("relic_type") == "shang_token") return 1;
        }
        if (req == "mine_blueprint" || req == "blueprint") {
            if (ob->id("mine blueprint") || ob->id("blueprint") || ob->id("殘圖")) return 1;
        }
        if (req == "steel_chisel" || req == "chisel") {
            if (ob->id("steel chisel") || ob->id("chisel") || ob->id("鋼鑿")) return 1;
        }
        if (req == "disha_wine" || req == "wine") {
            if (ob->id("disha wine") || ob->id("wine") || ob->id("烈酒")) return 1;
        }
        if (req == "mountain_talisman" || req == "talisman") {
            if (ob->id("mountain talisman") || ob->id("talisman") || ob->id("鎮山符")) return 1;
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

    int cur_stage = query_quest_stage(who, qid);
    mixed *steps = query_stage_steps(q, cur_stage);
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
        if (recovery && (recovery["from_npc"] == npc_id || npc_id == "any")) {
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

// ── 階段與任務結算處理器 (Stage / Quest Completion) ──────────

void handle_stage_completion(object who, string qid, mapping q, int cur_stage) {
    if (!who || !qid || !mapp(q)) return;

    mapping st_def = query_stage_def(q, cur_stage);
    int total_stages = (arrayp(q["stages"]) && sizeof(q["stages"]) > 0) ? sizeof(q["stages"]) : 1;

    // 發放該 Stage 的階段性獎勵
    if (st_def && st_def["on_finish"]) {
        mapping of_rew = st_def["on_finish"];
        if (of_rew["exp"]) who->add("exp", of_rew["exp"]);
        if (of_rew["fate"]) who->add("fate", of_rew["fate"]);
        if (of_rew["msg"]) tell_object(who, HIG + of_rew["msg"] + "\n" NOR);
    }

    // 判斷是否還有後續 Stage
    if (cur_stage < total_stages) {
        string fin_status = st_def ? st_def["status_on_finish"] : "dormant";
        if (fin_status == "dormant") {
            set_quest_state(who, qid, "DORMANT");
            set_quest_step(who, qid, query_quest_step(who, qid));
            tell_object(who, HIY "\n【✨ 階段達成】" + q["name"] + "（Stage " + sprintf("%d", cur_stage) + "・" + (st_def ? st_def["title"] : "") + "）已告一段落！\n" NOR);
            if (st_def && st_def["finish_desc"]) {
                tell_object(who, CYN + st_def["finish_desc"] + "\n" NOR);
            }
            if (st_def && st_def["next_region_hint"]) {
                tell_object(who, WHT "【天命指引】下一階段目標區域：【" + st_def["next_region_hint"] + "】（當前機緣隱伏，靜候出村踏入新地圖）\n\n" NOR);
            }
            return;
        } else {
            // 直接解鎖下一 Stage
            set_quest_stage(who, qid, cur_stage + 1);
            set_quest_step(who, qid, 1);
            set_quest_state(who, qid, "ACTIVE");
            tell_object(who, HIY "\n【✨ 進入下一階段】Stage " + sprintf("%d", cur_stage + 1) + "\n" NOR);
            return;
        }
    }

    // 若已無後續 Stage，完成整條任務
    if (q["type"] == "loop") {
        set_quest_step(who, qid, 0);
        int r = query_quest_rounds(who, qid) + 1;
        if (q["path_type"]) {
            who->set("task_chain/" + q["path_type"] + "_rounds", r);
        }
        who->set("quests/" + qid + "/rounds", r);
    } else {
        set_quest_step(who, qid, -1);
        set_quest_state(who, qid, "COMPLETED");
    }

    // 發放最終任務獎勵
    if (q["rewards"]) {
        mapping rw = q["rewards"];
        if (rw["exp"]) who->add("exp", rw["exp"]);
        if (rw["money"]) who->add_money(rw["money"]);
        if (rw["affinity"]) {
            mapping aff = rw["affinity"];
            foreach (string k, int v in aff) {
                who->add("affinity/" + k, v);
            }
        }
    }

    tell_object(who, HIY "\n【✨ 恭喜完成歷練：「" + q["name"] + "」！】\n" NOR);
}

// ── 事件觸發與推進器 (Event Dispatcher) ─────────────────────

mixed trigger_event(object who, string event_type, mapping data) {
    if (!who || !mapp(data)) return 0;

    string npc_id = data["npc"];
    string topic  = data["topic"];
    object item   = data["item"];
    string verb   = data["verb"];
    string target = data["target"];
    object npc_ob = data["npc_obj"];

    foreach (string qid, mapping q in quest_defs) {
        int cur_step = query_quest_step(who, qid);
        int cur_stage = query_quest_stage(who, qid);
        string q_state = query_quest_state(who, qid);

        mixed *steps = query_stage_steps(q, cur_stage);
        if (!arrayp(steps) || sizeof(steps) == 0) continue;

        // 若當前 Stage 處於 DORMANT 狀態：檢查是否滿足下一 stage 的解鎖條件
        if (q_state == "DORMANT") {
            int next_stage_num = cur_stage + 1;
            mapping next_stage = query_stage_def(q, next_stage_num);
            if (next_stage) {
                mapping unlock = next_stage["unlock_condition"];
                int can_unlock = 0;
                if (unlock) {
                    if (unlock["target_npc"] && event_type == "talk" && 
                        (npc_id == unlock["target_npc"] || (npc_ob && npc_ob->id(unlock["target_npc"]))) &&
                        (!unlock["target_topic"] || topic == unlock["target_topic"])) {
                        can_unlock = 1;
                    }
                }
                if (can_unlock) {
                    set_quest_stage(who, qid, next_stage_num);
                    set_quest_step(who, qid, 1);
                    set_quest_state(who, qid, "ACTIVE");
                    tell_object(who, HIY "\n【✨ 奇遇復甦】" + q["name"] + "（Stage " + sprintf("%d", next_stage_num) + "・" + next_stage["title"] + "）正式啟動！\n" NOR);
                    mixed *next_steps = query_stage_steps(q, next_stage_num);
                    if (sizeof(next_steps) > 0) {
                        tell_object(who, HIG "  指引：" + next_steps[0]["hint"] + "\n\n" NOR);
                    }
                    return 1;
                }
            }
            continue;
        }

        // 1. 若任務尚未接取 (step == 0)
        if (cur_step == 0) {
            // 方式 A: 向 start_npc 接取
            if (q["start_npc"] && event_type == "talk" && 
                (npc_id == q["start_npc"] || (npc_ob && npc_ob->id(q["start_npc"]))) && 
                (!q["start_topic"] || topic == q["start_topic"])) {
                set_quest_stage(who, qid, 1);
                set_quest_step(who, qid, 1);
                set_quest_state(who, qid, "ACTIVE");
                tell_object(who, HIG "【接取歷練任務】" + q["name"] + "\n" +
                                     "  目標：" + steps[0]["hint"] + "\n" NOR);
                return 1;
            }
            // 方式 B: 隱藏奇遇在 step 1 透過 action 行為直接觸發接取
            mapping s0 = steps[0];
            if (s0["target_type"] == "action" && event_type == "action" && verb == s0["action_verb"]) {
                if (!s0["action_target"] || target == s0["action_target"]) {
                    set_quest_stage(who, qid, 1);
                    set_quest_state(who, qid, "ACTIVE");
                    mapping st1 = query_stage_def(q, 1);
                    tell_object(who, HIY "\n【✨ 奇遇觸發・" + q["name"] + "】\n" NOR);
                    tell_object(who, CYN "你在這方邊陲之地觸動了失落的史前機緣，已踏上「Stage 1・" + (st1 ? st1["title"] : "始動") + "」！\n" NOR);

                    // 發放 step 1 完成回饋
                    if (s0["on_complete"]) {
                        mapping oc0 = s0["on_complete"];
                        if (oc0["give_item"]) {
                            object r0 = clone_object(oc0["give_item"]);
                            if (r0) {
                                if (r0->query("is_relic") && present(r0->query_name(), who)) {
                                    destruct(r0);
                                } else {
                                    r0->move(who);
                                    tell_object(who, HIG "【獲得信物：" + r0->query_short() + "】\n" NOR);
                                }
                            }
                        }
                        if (oc0["msg"]) {
                            tell_object(who, HIG + oc0["msg"] + "\n" NOR);
                        }
                    }

                    // 直接推進至第 2 步
                    if (sizeof(steps) > 1) {
                        set_quest_step(who, qid, 2);
                        tell_object(who, HIG "【任務推進】第 2 步：" + steps[1]["hint"] + "\n\n" NOR);
                    } else {
                        handle_stage_completion(who, qid, q, cur_stage);
                    }
                    return 1;
                }
            }
            continue;
        }

        // 2. 檢查信物遺失補領判定 (Lost Item Fallback)
        mapping recovery = check_lost_item(who, qid);
        if (recovery && event_type == "talk") {
            if ((npc_id == recovery["from_npc"] || (npc_ob && npc_ob->id(recovery["from_npc"]))) && 
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
                if ((npc_id == s["target_npc"] || (npc_ob && npc_ob->id(s["target_npc"]))) && 
                    (!s["target_topic"] || topic == s["target_topic"])) {
                    string req = s["require_item"];
                    if (!req || req == "" || has_required_item(who, req)) {
                        matched = 1;
                    } else {
                        tell_object(who, HIR "你身上似乎缺少了對話所需的關鍵信物！\n" NOR);
                    }
                }
            } else if (t_type == "deliver" && event_type == "deliver") {
                if (npc_id == s["target_npc"] || (npc_ob && npc_ob->id(s["target_npc"]))) {
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
                            if (reward_ob->query("is_relic") && present(reward_ob->query_name(), who)) {
                                destruct(reward_ob);
                            } else {
                                reward_ob->move(who);
                                tell_object(who, HIG "【獲得道具：" + reward_ob->query_short() + "】\n" NOR);
                            }
                        }
                    }
                    if (oc["msg"]) {
                        tell_object(who, HIG + oc["msg"] + "\n" NOR);
                    }
                }

                // 推進到下一步
                int next_step = cur_step + 1;
                if (next_step > sizeof(steps)) {
                    handle_stage_completion(who, qid, q, cur_stage);
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
    int cur_stage = query_quest_stage(who, qid);
    string q_state = query_quest_state(who, qid);

    // 1. 道統鏈渲染 (維持專用親和度與輪次格式)
    if (q["path_type"]) {
        int rounds = query_quest_rounds(who, qid);
        int aff = who->query("affinity/" + q["path_type"]);
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

    // 2. 多階段史詩/奇遇任務 (以 Stage 為宏觀單位)
    if (arrayp(q["stages"]) && sizeof(q["stages"]) > 0) {
        int total_st = sizeof(q["stages"]);
        string state_badge = "";
        if (q_state == "DORMANT") {
            state_badge = YEL " [Stage " + sprintf("%d", cur_stage) + " 達成・靜候天時]" NOR;
        } else if (q_state == "COMPLETED") {
            state_badge = HIG " [全線圓滿]" NOR;
        } else if (cur_step > 0) {
            state_badge = HIY " [Stage " + sprintf("%d/%d", cur_stage, total_st) + " 進行中]" NOR;
        } else {
            state_badge = WHT " [未觸發]" NOR;
        }

        string out = sprintf(HIW "【%s】" NOR "%s\n", q["name"], state_badge);

        for (int i = 0; i < total_st; i++) {
            mapping st_def = q["stages"][i];
            int s_num = st_def["stage"];
            string st_title = st_def["title"];
            string region = st_def["region_name"] ? st_def["region_name"] : st_def["region"];

            if (cur_step == 0) {
                out += sprintf(CYN "  [ ] Stage %d：%s (%s)\n" NOR, s_num, st_title, region);
            } else if (s_num < cur_stage || (s_num == cur_stage && q_state == "DORMANT")) {
                out += sprintf(HIG "  [✓] Stage %d：%s (%s - 已完成)\n" NOR, s_num, st_title, region);
                if (s_num == cur_stage && q_state == "DORMANT") {
                    if (st_def["finish_desc"]) {
                        out += sprintf(CYN "      階段結語：%s\n" NOR, st_def["finish_desc"]);
                    }
                    if (st_def["next_region_hint"]) {
                        out += sprintf(HIY "      天命指引：此機緣暫時沉寂，待踏入【%s】後方可喚醒後續 Stage %d 機緣。\n" NOR,
                                      st_def["next_region_hint"], s_num + 1);
                    }
                }
            } else if (s_num == cur_stage) {
                out += sprintf(HIY "  [▶] Stage %d：%s (%s - 進行中)\n" NOR, s_num, st_title, region);
                mixed *st_steps = st_def["steps"];
                if (arrayp(st_steps)) {
                    for (int j = 0; j < sizeof(st_steps); j++) {
                        mapping ss = st_steps[j];
                        int ss_num = ss["step"];
                        if (cur_step > ss_num) {
                            out += sprintf(HIG "      [✓] 第 %d 步：%s\n" NOR, ss_num, ss["title"]);
                        } else if (cur_step == ss_num) {
                            out += sprintf(HIY "      [▶] 第 %d 步：%s (進行中)\n" NOR, ss_num, ss["title"]);
                            out += sprintf(WHT "          指引：%s\n" NOR, ss["hint"]);
                            string req = ss["require_item"];
                            if (req && req != "" && !has_required_item(who, req)) {
                                mapping recovery = ss["lost_item_recovery"];
                                if (recovery) {
                                    out += sprintf(HIR "          ⚠️ 身上缺少關鍵信物，可前往向【%s】詢問「%s」補領！\n" NOR,
                                                  recovery["from_npc"], recovery["ask_topic"]);
                                } else {
                                    out += sprintf(HIR "          ⚠️ 身上缺少關鍵交付物品【%s】！\n" NOR, req);
                                }
                            }
                        } else {
                            out += sprintf(GRN "      [ ] 第 %d 步：%s\n" NOR, ss_num, ss["title"]);
                        }
                    }
                }
            } else {
                out += sprintf(WHT "  [ ] Stage %d：%s (待解鎖・需前往 %s)\n" NOR, s_num, st_title, region);
            }
        }
        return out;
    }

    // 3. 一般單階支線/主線
    string out = sprintf(HIW "【%s】\n" NOR, q["name"]);
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
    
    // 1. 三大道統鏈
    string *career_chains = ({ "wu_chain", "li_chain", "fa_chain" });
    foreach (string qid in career_chains) {
        if (quest_defs[qid]) {
            out += query_quest_checklist(who, qid) + "\n";
        }
    }

    // 2. 史詩奇遇與長線隱藏線索
    string *epic_list = ({ "ancient_order" });
    int has_epic = 0;
    foreach (string qid in epic_list) {
        if (quest_defs[qid]) {
            int step = who->query("quests/" + qid + "/step");
            string st = who->query("quests/" + qid + "/state");
            if (step > 0 || st == "DORMANT" || st == "COMPLETED") {
                if (!has_epic) {
                    out += HIY "---------------- 史詩奇遇與天命線索 ----------------\n" NOR;
                    has_epic = 1;
                }
                out += query_quest_checklist(who, qid) + "\n";
            }
        }
    }

    out += HIW "======================================================\n" NOR;
    return out;
}
