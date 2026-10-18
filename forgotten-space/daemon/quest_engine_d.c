// daemon/quest_engine_d.c
// 《遺忘的世界》抽象化任務引擎守護進程 (QUEST_ENGINE_D)
// 支援基於 /quests/*.json 的跨地圖多階段 (stages) 狀態機、信物遺失自動補領與結構化進度追蹤

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/object.c";

mapping quest_defs;
mapping encounter_defs;
mapping legacy_encounter_map;

void load_all_quests();
void handle_stage_completion(object who, string qid, mapping q, int cur_stage);
mapping query_stage_def(mapping q, int stage_num);
mixed *query_stage_steps(mapping q, int stage_num);
void audit_encounter(string enc_id, mapping enc, string path);
mapping query_encounter(string enc_id);
string query_encounter_id_by_legacy(string legacy_key);
mixed evaluate_encounter(object who, string enc_id, mapping ctx);
int is_event_quest_stage_valid(mapping q);
mapping apply_world_event_outcome(object who, string qid, mapping q);

void create() {
    ::create();
    quest_defs = ([]);
    encounter_defs = ([]);
    legacy_encounter_map = ([]);
    load_all_quests();
}

// 任務語義與合法性稽核器 (Quest Definition Auditor)
void audit_quest(string qid, mapping q, string path) {
    if (!q) return;

    if (!q["name"] || q["name"] == "") {
        write_file("/log/quest_error.log", sprintf("[QUEST_AUDIT] 警告：任務 '%s' (%s) 缺少 name\n", qid, path), 0);
    }

    // 稽核事件型任務欄位 (World Event Quest Schema Audit)
    if (q["world_event"]) {
        string *valid_event_metrics = ({
            "herd_pressure", "route_confidence", "diversion_effect",
            "settlement_capacity", "evidence_strength", "civilian_trust",
            "intel_confidence", "evidence_verifiability", "assault_cost", "settlement_resilience"
        });
        string *valid_event_facts = ({
            "autopsy_performed", "sulfur_poisoning_found", "flight_direction_mapped",
            "diversion_ditch_dug", "cold_smoke_stock", "signal_arrows_ready",
            "merchant_fled", "merchant_supplies_looted", "canyon_road_destroyed", "residual_breach_occurred"
        });
        if (q["eval_metric"] && member_array(q["eval_metric"], valid_event_metrics) == -1) {
            write_file("/log/quest_error.log", sprintf("[QUEST_AUDIT ERROR] 事件任務 '%s' eval_metric 非法：%s\n", qid, q["eval_metric"]), 0);
        }
        if (q["eval_min_for_success"] && !intp(q["eval_min_for_success"])) {
            write_file("/log/quest_error.log", sprintf("[QUEST_AUDIT ERROR] 事件任務 '%s' eval_min_for_success 需為整數\n", qid), 0);
        }
        if (q["deadline_stage"] && !stringp(q["deadline_stage"])) {
            write_file("/log/quest_error.log", sprintf("[QUEST_AUDIT ERROR] 事件任務 '%s' deadline_stage 需為字串\n", qid), 0);
        }
        if (q["valid_stages"] && !arrayp(q["valid_stages"])) {
            write_file("/log/quest_error.log", sprintf("[QUEST_AUDIT ERROR] 事件任務 '%s' valid_stages 需為陣列\n", qid), 0);
        }
        if (!mapp(q["event_outcomes"]) || !q["event_outcomes"]["success"]) {
            write_file("/log/quest_error.log", sprintf("[QUEST_AUDIT ERROR] 事件任務 '%s' 缺少 event_outcomes.success\n", qid), 0);
        } else {
            foreach (string grade_key in ({ "success", "partial", "failure" })) {
                mapping oc = q["event_outcomes"][grade_key];
                if (!mapp(oc)) continue;
                if (!oc["status"] || !oc["message"]) {
                    write_file("/log/quest_error.log", sprintf("[QUEST_AUDIT] 警告：事件任務 '%s' 分支 '%s' 缺少 status 或 message\n", qid, grade_key), 0);
                }
                if (mapp(oc["deltas"])) {
                    foreach (string mk, int dv in oc["deltas"]) {
                        if (member_array(mk, valid_event_metrics) == -1) {
                            write_file("/log/quest_error.log", sprintf("[QUEST_AUDIT ERROR] 事件任務 '%s' 未註冊指標：%s\n", qid, mk), 0);
                        }
                    }
                }
                if (mapp(oc["facts"])) {
                    foreach (string fk, mixed fv in oc["facts"]) {
                        if (member_array(fk, valid_event_facts) == -1) {
                            write_file("/log/quest_error.log", sprintf("[QUEST_AUDIT ERROR] 事件任務 '%s' 未註冊事實：%s\n", qid, fk), 0);
                        }
                    }
                }
                foreach (string ev_field in ({ "evidence", "extra_evidence" })) {
                    mapping ev_def = oc[ev_field];
                    if (mapp(ev_def)) {
                        if (!ev_def["id"] || !ev_def["source_type"] || !ev_def["strength"] || !ev_def["verified"]) {
                            write_file("/log/quest_error.log", sprintf("[QUEST_AUDIT] 警告：事件任務 '%s' 物證欄位不完整\n", qid), 0);
                        }
                    }
                }
            }
        }
    }

    mixed *all_steps = ({});
    if (arrayp(q["stages"]) && sizeof(q["stages"]) > 0) {
        int total_st = sizeof(q["stages"]);
        for (int i = 0; i < total_st; i++) {
            mapping st = q["stages"][i];
            if (!st["stage"]) {
                write_file("/log/quest_error.log", sprintf("[QUEST_AUDIT] 警告：任務 '%s' 階段索引 %d 缺少 stage 編號\n", qid, i), 0);
            }
            if (i == total_st - 1) {
                if (!st["on_finish"] && !st["rewards"] && !q["rewards"]) {
                    write_file("/log/quest_error.log", sprintf("[QUEST_AUDIT] 警告：任務 '%s' 終局階段 %d 未定義結算獎勵 (on_finish/rewards)\n", qid, i + 1), 0);
                }
            }
            if (arrayp(st["steps"])) {
                all_steps += st["steps"];
            }
        }
    } else if (arrayp(q["steps"])) {
        all_steps = q["steps"];
        if (!q["rewards"] && !q["on_finish"]) {
            write_file("/log/quest_error.log", sprintf("[QUEST_AUDIT] 警告：任務 '%s' 未定義任務獎勵 (rewards)\n", qid), 0);
        }
    }

    for (int j = 0; j < sizeof(all_steps); j++) {
        mapping s = all_steps[j];
        int s_idx = s["step"];
        string loc = s["location"] ? s["location"] : s["room"];
        if (loc && loc != "") {
            string chk = loc;
            if (strsrch(chk, ".c") == -1) chk += ".c";
            if (file_size(chk) < 0) {
                write_file("/log/quest_error.log", sprintf("[QUEST_AUDIT ERROR] 任務 '%s' 第 %d 步關聯房間不存在：%s\n", qid, s_idx, chk), 0);
            }
        }

        if (s["on_complete"] && s["on_complete"]["give_item"]) {
            string itm = s["on_complete"]["give_item"];
            if (strsrch(itm, ".c") == -1) itm += ".c";
            if (file_size(itm) < 0) {
                write_file("/log/quest_error.log", sprintf("[QUEST_AUDIT ERROR] 任務 '%s' 第 %d 步發放道具不存在：%s\n", qid, s_idx, itm), 0);
            }
        }
    }
}

// 奇遇語義與稀有規格稽核器 (Encounter Definition Auditor)
void audit_encounter(string enc_id, mapping enc, string path) {
    if (!enc) return;
    if (!enc["name"] || enc["name"] == "") {
        write_file("/log/quest_error.log", sprintf("[ENCOUNTER_AUDIT] 警告：奇遇 '%s' (%s) 缺少 name\n", enc_id, path), 0);
    }
    if (!enc["gates"] || !arrayp(enc["gates"])) {
        write_file("/log/quest_error.log", sprintf("[ENCOUNTER_AUDIT] 警告：奇遇 '%s' 缺少門檻閘道 (gates)\n", enc_id), 0);
    }
    if (!enc["roll"]) {
        write_file("/log/quest_error.log", sprintf("[ENCOUNTER_AUDIT] 警告：奇遇 '%s' 缺少機率骰點配置 (roll)\n", enc_id), 0);
    }
    if (!enc["scope"] || !enc["scope"]["slots"]) {
        write_file("/log/quest_error.log", sprintf("[ENCOUNTER_AUDIT] 警告：奇遇 '%s' 缺少全服限量名額 (scope.slots)\n", enc_id), 0);
    }
    if (!enc["recovery"] || !enc["recovery"]["policy"]) {
        write_file("/log/quest_error.log", sprintf("[ENCOUNTER_AUDIT] 警告：奇遇 '%s' 缺少回聲政策配置 (recovery.policy)\n", enc_id), 0);
    }
}

// 載入指定 JSON 檔案並加入任務池 (包含規格防呆檢定)
int load_quest_file(string path) {
    string content = read_file(path);
    if (!content || content == "") return 0;

    mixed def = json_decode(content);
    if (!mapp(def) || !def["id"]) {
        write_file("/log/quest_error.log", "[QUEST_ENGINE] 錯誤：檔案非合法 JSON 或缺少 id: " + path + "\n", 0);
        return 0;
    }

    if (!def["name"] || def["name"] == "") {
        write_file("/log/quest_error.log", "[QUEST_ENGINE] 警告：定義缺少 name: " + path + "\n", 0);
    }

    if (def["gates"] || (strlen(def["id"]) > 4 && substr(def["id"], 0, 4) == "enc_")) {
        audit_encounter(def["id"], def, path);
        encounter_defs[def["id"]] = def;
        if (def["legacy_key"]) {
            legacy_encounter_map[def["legacy_key"]] = def["id"];
        }
    } else {
        audit_quest(def["id"], def, path);
        quest_defs[def["id"]] = def;
    }
    return 1;
}

// 掃描 /quests/ 各子目錄下的所有 JSON 任務定義檔
void load_all_quests() {
    quest_defs = ([]);
    encounter_defs = ([]);
    legacy_encounter_map = ([]);

    string *subdirs = ({ "", "career/", "main/", "side/", "epic/", "loop/", "encounter/", "event/" });
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
        "/quests/side/hunting_chain.json",
        "/quests/loop/mining_loop.json",
        "/quests/loop/herb_loop.json",
        "/quests/loop/pelt_loop.json",
        "/quests/main/village_pass.json",
        "/quests/main/cycle_of_craft.json",
        "/quests/main/rescue_maiden.json",
        "/quests/main/rescue_miners.json",
        "/quests/epic/ancient_order.json",
        "/quests/encounter/enc_stele_dawn.json",
        "/quests/encounter/enc_ancient_iron.json",
        "/quests/encounter/enc_forest_totem.json",
        "/quests/encounter/enc_dao_crystal.json",
        "/quests/encounter/enc_tianmen_token.json",
        "/quests/encounter/enc_map_fusion.json",
        "/quests/event/a01_dead_gazelle.json",
        "/quests/event/a02_reverse_tracks.json",
        "/quests/event/b02_rockfall_diversion.json",
        "/quests/event/c01_grain_inventory.json",
        "/quests/event/d01_last_painkiller.json",
        "/quests/event/e01_street_defense.json",
        "/quests/event/g01_palisade_breach.json",
        "/quests/event/f03_testimony_cross_check.json"
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
            foreach (string eid, mapping e in encounter_defs) {
                if (e["id"] && strsrch(path, e["id"]) != -1) {
                    found = 1;
                    break;
                }
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

mapping query_encounter(string enc_id) {
    if (!enc_id || enc_id == "") return 0;
    if (encounter_defs[enc_id]) return encounter_defs[enc_id];
    if (legacy_encounter_map[enc_id]) return encounter_defs[legacy_encounter_map[enc_id]];
    return 0;
}

mapping query_all_encounters() {
    return encounter_defs;
}

string query_encounter_id_by_legacy(string legacy_key) {
    if (!legacy_key || legacy_key == "") return 0;
    return legacy_encounter_map[legacy_key];
}

// ── 奇遇三階段評估分派器 (Encounter Evaluator: Anomaly -> Resonance -> Consequence) ──
mixed evaluate_encounter(object who, string raw_enc_id, mapping ctx) {
    if (!who || !raw_enc_id || raw_enc_id == "") return 0;

    string enc_id = raw_enc_id;
    if (!encounter_defs[enc_id] && legacy_encounter_map[enc_id]) {
        enc_id = legacy_encounter_map[enc_id];
    }

    mapping enc = encounter_defs[enc_id];
    if (!enc) {
        write_file("/log/quest_error.log", sprintf("[EVAL_ENCOUNTER ERROR] 未知奇遇 ID：%s\n", raw_enc_id), 0);
        return 0;
    }

    // 0. 重複性檢驗 (若非測試模式且已達成正品或回聲，不再重複觸發)
    if (who->query("personal_event/" + enc_id) || (enc["legacy_key"] && who->query("personal_event/" + enc["legacy_key"]))) {
        if (!ctx || !ctx["force_eval"]) {
            tell_object(who, CYN "你此前已勘破此處太古天機，此地遺物與道韻已被你洞悉，無需重複參悟。\n" NOR);
            return 1;
        }
    }

    // ── 階段一：發現異常 (Gate 檢定：世界窗口、身世血脈、共鳴門檻、多人合契) ──
    if (arrayp(enc["gates"])) {
        foreach (mapping g in enc["gates"]) {
            string gtype = g["type"];

            // 1. 世界窗口檢定 (獨立排程)
            if (gtype == "world_window") {
                string wid = g["id"];
                object ws = load_object(WORLD_STATE_D);
                if (ws && !ws->is_window_active(wid) && !wizardp(who) && (!ctx || !ctx["ignore_window"])) {
                    string wdesc = g["desc"] ? g["desc"] : wid;
                    tell_object(who, CYN "此處天地異象未生（世界窗口【" + wdesc + "】未開啟），古蹟沉寂無聲。\n" NOR);
                    return -1;
                }
            }

            // 2. 身世血統排他性檢定
            if (gtype == "background") {
                string my_bg = who->query("background");
                string my_nick = who->query("nickname");
                int match_bg = 0;
                if (arrayp(g["any"])) {
                    foreach (string bg in g["any"]) {
                        if (my_bg == bg) { match_bg = 1; break; }
                        if (my_nick) {
                            if (bg == "herbalist" && (my_nick == "顧玄" || my_nick == "採藥人")) match_bg = 1;
                            if (bg == "smith" && (my_nick == "林鐵生" || my_nick == "鐵匠")) match_bg = 1;
                            if (bg == "hunter" && (my_nick == "燕隼" || my_nick == "獵戶")) match_bg = 1;
                            if (bg == "daoist" && (my_nick == "柳清虛" || my_nick == "道童")) match_bg = 1;
                            if (bg == "beggar" && (my_nick == "沈泥" || my_nick == "乞兒")) match_bg = 1;
                        }
                    }
                }
                if (!match_bg && !wizardp(who) && (!ctx || !ctx["ignore_bg"])) {
                    tell_object(who, CYN "你看著眼前的古物，受限於凡俗常人靈覺與身世血脈，只覺其平平無奇，無法勘破深層道韻。（身世血脈不合）\n" NOR);
                    return -2;
                }
            }

            // 3. 屬性/天命共鳴檢定
            if (gtype == "resonance") {
                string stat_name = g["stat"];
                int min_v = g["min"];
                int cur_v = 0;
                if (stat_name == "fate") cur_v = who->query(STAT_FATE);
                else cur_v = who->query_stat(stat_name);
                if (cur_v < min_v && !wizardp(who) && (!ctx || !ctx["ignore_resonance"])) {
                    tell_object(who, YEL "你的靈性與神魂共鳴尚淺，不足以引動太古異象。（需 " + stat_name + " >= " + min_v + "）\n" NOR);
                    return 0;
                }
            }

            // 4. 多人/多身世合作拼合檢定 (小說第 9 章暗巷機制)
            if (gtype == "coop") {
                int min_u = g["min_unique_backgrounds"];
                int min_p = g["min_players"] ? g["min_players"] : 1;
                if (min_u > 1 || min_p > 1) {
                    int unique_bgs = 1;
                    string my_bg = who->query("background");
                    object env = environment(who);
                    if (env) {
                        object *inv = all_inventory(env);
                        foreach (object ob in inv) {
                            if (ob && ob->is_character() && ob != who) {
                                string ob_bg = ob->query("background");
                                if (ob_bg && ob_bg != "" && ob_bg != my_bg) {
                                    unique_bgs++;
                                    break;
                                }
                            }
                        }
                    }
                    if (unique_bgs < min_u) {
                        int alt_found = 0;
                        if (my_bg != "daoist" && (who->query("encounter_clues/frost_trace") || present("dao crystal", who) || present("crystal", who))) alt_found = 1;
                        if (my_bg != "herbalist" && (who->query("encounter_clues/stele_trace") || present("stele rubbing", who) || present("rubbing", who))) alt_found = 1;
                        if (my_bg != "smith" && (who->query("encounter_clues/iron_slag_clue") || present("ancient black iron", who) || present("black iron", who))) alt_found = 1;
                        if (my_bg != "hunter" && (who->query("encounter_clues/totem_trace") || present("totem fragment", who))) alt_found = 1;
                        if (my_bg != "beggar" && (who->query("encounter_clues/gear_rattle") || present("tianmen token", who) || present("token", who))) alt_found = 1;
                        if (alt_found) unique_bgs++;
                    }
                    if (unique_bgs < min_u && !wizardp(who) && (!ctx || !ctx["ignore_coop"])) {
                        tell_object(who, YEL "【合契未成】太古星圖殘卷需至少兩道截然不同的大道身世（如物修草藥師與法修道童，或同室道友印證）共同比對，方能嚴絲合縫拼合！\n" NOR);
                        return 0;
                    }
                }
            }
        }
    }

    // ── 階段二：成立共鳴 (代價扣除、反噬衝擊、骰點與 Pity 保底) ──
    string vital_type = "sen";
    int cost_amt = 10;
    mapping backlash = 0;
    if (arrayp(enc["gates"])) {
        foreach (mapping g in enc["gates"]) {
            if (g["type"] == "cost") {
                if (g["vital"]) vital_type = g["vital"];
                if (g["amount"]) cost_amt = g["amount"];
                backlash = g["backlash"];
                break;
            }
        }
    }

    string vital_prop = VITAL_SEN;
    if (vital_type == "kee") vital_prop = VITAL_KEE;
    else if (vital_type == "sp") vital_prop = VITAL_SP;

    if (who->query(vital_prop) < cost_amt && !wizardp(who)) {
        tell_object(who, HIR "你心神/氣血損耗過劇，無法強行引動心神與古蹟共鳴！（需 " + vital_type + " " + cost_amt + " 點）\n" NOR);
        return 0;
    }
    who->add(vital_prop, -cost_amt);

    // 觸發反噬
    if (backlash && random(100) < to_int(backlash["chance"] * 100)) {
        tell_object(who, HIR + "【道韻反噬】" + backlash["msg"] + "\n" NOR);
        who->add(vital_prop, -cost_amt / 2);
        if (backlash["effect"]) {
            who->set_temp("backlash_effect/" + backlash["effect"], time());
        }
    }

    // 骰點計算 (包含 Pity 保底)
    float base_rate = 0.4;
    float per_miss = 0.2;
    float cap_rate = 1.0;
    if (enc["roll"]) {
        if (enc["roll"]["base"]) base_rate = enc["roll"]["base"];
        if (enc["roll"]["pity"]) {
            if (enc["roll"]["pity"]["per_miss"]) per_miss = enc["roll"]["pity"]["per_miss"];
            if (enc["roll"]["pity"]["cap"]) cap_rate = enc["roll"]["pity"]["cap"];
        }
    }

    int pity_misses = who->query("encounter_pity/" + enc_id);
    float total_rate = base_rate + (pity_misses * per_miss);
    if (total_rate > cap_rate) total_rate = cap_rate;

    int roll_val = random(1000);
    int target_val = to_int(total_rate * 1000);

    if (roll_val >= target_val && (!ctx || !ctx["force_success"])) {
        // 未過：留下線索與積累保底
        who->add("encounter_pity/" + enc_id, 1);
        if (enc["on_fail"]) {
            if (enc["on_fail"]["clue"]) who->set("encounter_clues/" + enc["on_fail"]["clue"], 1);
            if (enc["on_fail"]["msg"]) tell_object(who, YEL + enc["on_fail"]["msg"] + "\n" NOR);
        }
        return 0;
    }

    // ── 階段三：留下後果 (正品分配 vs 回聲政策) ──
    who->delete("encounter_pity/" + enc_id);

    int max_slots = 3;
    string slot_per = "season";
    if (enc["scope"]) {
        if (enc["scope"]["slots"]) max_slots = enc["scope"]["slots"];
        if (enc["scope"]["per"]) slot_per = enc["scope"]["per"];
    }

    object ws = load_object(WORLD_STATE_D);
    int got_slot = ws ? ws->consume_encounter_slot(enc_id, max_slots) : 1;
    if (ctx && ctx["force_echo"]) got_slot = 0;

    if (got_slot) {
        // 1. 成功獲取正品神物
        who->set("personal_event/" + enc_id, 1);
        if (enc["legacy_key"]) {
            who->set("personal_event/" + enc["legacy_key"], 1);
            who->set(enc["legacy_key"], 1);
        }
        if (enc["rewards"]) {
            if (enc["rewards"]["exp"]) who->gain_exp(enc["rewards"]["exp"]);
            if (enc["rewards"]["pot"]) who->add("potential", enc["rewards"]["pot"]);
            if (enc["rewards"]["fate"]) {
                int cur_f = who->query(STAT_FATE);
                who->set(STAT_FATE, cur_f + enc["rewards"]["fate"]);
                tell_object(who, HIY "【宿命共鳴】你觸及了一角太古真相，體內沉睡的天命微幅覺醒（天命 +" +
                                 sprintf("%d", enc["rewards"]["fate"]) + "，當前天命：" + sprintf("%d", cur_f + enc["rewards"]["fate"]) + "）！\n" NOR);
            }
            if (enc["rewards"]["title"]) who->set("title", enc["rewards"]["title"]);
            if (enc["rewards"]["clue_key"]) who->set("encounter_clues/" + enc["rewards"]["clue_key"], 1);
            if (enc["rewards"]["clone_item"]) {
                object item = clone_object(enc["rewards"]["clone_item"]);
                if (item) {
                    if (!item->move(who) && environment(who)) item->move(environment(who));
                }
            }
        }
        tell_object(who, HIG "【道契圓融】太古異象在靈台中轟然洞開，你成功勘破了【" + enc["name"] + "】的神機！（獲得神物正品）\n" NOR);
        return 1;
    } else {
        // 2. 名額耗盡 -> 回聲政策 (Echo Policy)
        who->set("personal_event/" + enc_id, 1);
        who->set("personal_event/" + enc_id + "_echo", 1);
        if (enc["legacy_key"]) {
            who->set("personal_event/" + enc["legacy_key"], 1);
            who->set(enc["legacy_key"], 1);
        }
        if (enc["rewards"]) {
            if (enc["rewards"]["exp"]) who->gain_exp(enc["rewards"]["exp"] / 2);
            if (enc["rewards"]["clue_key"]) who->set("encounter_clues/" + enc["rewards"]["clue_key"], 1);
        }
        if (enc["recovery"] && enc["recovery"]["echo_item"]) {
            object echo_item = clone_object(enc["recovery"]["echo_item"]);
            if (echo_item) {
                if (!echo_item->move(who) && environment(who)) echo_item->move(environment(who));
            }
        }
        string echo_desc = enc["recovery"] ? enc["recovery"]["echo_desc"] : "一枚無神力的拓本抄片";
        tell_object(who, HIY "【天地回聲】本季太古神物名額已散入天地，你獲得了神力消弭的太古遺物殘響拓本（回聲）！\n" +
                         WHT + echo_desc + "\n" NOR);
        return 2;
    }
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

// 輔助函式：NPC 匹配比對（支援字串、陣列或 "any"）
int npc_matches(mixed target_npc, string npc_id, object npc_ob) {
    if (!target_npc) return 0;
    if (stringp(target_npc)) {
        if (target_npc == "any") return 1;
        if (npc_id == target_npc) return 1;
        if (npc_ob && npc_ob->id(target_npc)) return 1;
        return 0;
    }
    if (arrayp(target_npc)) {
        for (int i = 0; i < sizeof(target_npc); i++) {
            string tn = target_npc[i];
            if (tn == "any" || npc_id == tn || (npc_ob && npc_ob->id(tn))) return 1;
        }
    }
    return 0;
}

// 輔助函式：對話話題匹配比對（支援逗號隔開、陣列或精確比對）
int topic_matches(mixed target_topic, string topic) {
    if (!target_topic || target_topic == "" || target_topic == "any") return 1;
    if (!topic || topic == "") return 0;
    if (stringp(target_topic)) {
        if (topic == target_topic) return 1;
        if (strsrch(target_topic, ",") != -1) {
            string *parts = explode(target_topic, ",");
            for (int i = 0; i < sizeof(parts); i++) {
                if (trim(parts[i]) == topic) return 1;
            }
        }
        return 0;
    }
    if (arrayp(target_topic)) {
        for (int i = 0; i < sizeof(target_topic); i++) {
            if (target_topic[i] == topic) return 1;
        }
    }
    return 0;
}

// ── 信物檢查與丟失補領判定 ─────────────────────────────────

// 檢查玩家身上是否持有特定信物
int has_required_item(object who, string req) {
    if (!who || !req || req == "") return 1;

    // 1. 直接 present 尋找 id（支援底線與空白互轉）
    if (present(req, who)) return 1;
    if (strsrch(req, "_") != -1 && present(replace_string(req, "_", " "), who)) return 1;

    // 2. 依型別別名與特徵屬性判斷
    object *inv = all_inventory(who);
    foreach (object ob in inv) {
        if (req == "herb" || req == "herb_common") {
            if (ob->query("herb_type") || ob->id("herb") || ob->id("草藥")) return 1;
        }
        if (req == "wolf_fur" || req == "fur") {
            if (ob->id("wolf fur") || ob->id("wolf_fur") || ob->id("fur") || ob->id("狼皮")) return 1;
        }
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

// 統一獎勵發放器 (全維度支援：經驗、潛能、錢幣、天命、道統親和度、獎勵物品，並支援勞動收益遞減)
varargs void award_rewards(object who, mapping rw, string qid) {
    if (!who || !mapp(rw)) return;

    mapping actual_rw = ([]);
    foreach (mixed k, mixed v in rw) {
        actual_rw[k] = v;
    }

    // 檢查是否配置了收益遞減 (如日常單一循環任務)
    if (qid && stringp(qid) && quest_defs[qid] && quest_defs[qid]["decay_config"]) {
        mapping decay = quest_defs[qid]["decay_config"];
        int round = query_quest_rounds(who, qid);
        int exp_rounds = decay["exp_rounds"] ? decay["exp_rounds"] : 3;
        int taper_rounds = decay["taper_rounds"] ? decay["taper_rounds"] : 5;
        int cutoff_round = decay["cutoff_round"] ? decay["cutoff_round"] : 6;

        if (round >= cutoff_round) {
            // 保底只剩物質獎勵！經驗值與潛能直接歸零
            actual_rw["exp"] = 0;
            actual_rw["pot"] = 0;
            mapping q_info = quest_defs[qid];
            string q_label = (q_info && q_info["name"]) ? q_info["name"] : "生計勞作";
            tell_object(who, WHT "【勞作收益】你今日已完成第 " + sprintf("%d", round) + " 輪" + q_label + "，體悟已達瓶頸（不再獲得經驗與潛能），僅獲取工錢與原料物資！\n" NOR);
            if (decay["material_floor"]) {
                mapping mf = decay["material_floor"];
                if (mf["items"]) {
                    mixed cur_itms = actual_rw["items"];
                    if (!cur_itms) actual_rw["items"] = mf["items"];
                    else if (arrayp(cur_itms)) actual_rw["items"] += mf["items"];
                    else actual_rw["items"] = ({ cur_itms }) + mf["items"];
                }
                if (mf["money"]) actual_rw["money"] = mf["money"];
            }
        } else if (round > exp_rounds) {
            // 遞減區間（減半）
            if (actual_rw["exp"]) actual_rw["exp"] = actual_rw["exp"] / 2;
            if (actual_rw["pot"]) actual_rw["pot"] = actual_rw["pot"] / 2;
            tell_object(who, YEL "【勞動遞減】今日已完成第 " + sprintf("%d", round) + " 輪，勞動疲憊使經驗與潛能收益減半。\n" NOR);
        }
    }

    if (actual_rw["exp"]) {
        who->gain_exp(actual_rw["exp"]);
    }
    if (actual_rw["pot"]) {
        int pot_val = actual_rw["pot"];
        who->gain_potential(pot_val);
        tell_object(who, HIY "【修為潛能】獲得 " + sprintf("%d", pot_val) + " 點潛能！\n" NOR);
    }
    if (actual_rw["money"]) {
        who->add_money(actual_rw["money"]);
    }
    if (actual_rw["gold"]) {
        who->gain_gold(actual_rw["gold"]);
    }
    if (actual_rw["fate"]) {
        int f_val = actual_rw["fate"];
        who->add("fate", f_val);
        tell_object(who, HIM "【天命烙印】天命隱性覺醒度提升了 " + sprintf("%d", f_val) + " 點！\n" NOR);
    }
    if (actual_rw["affinity"]) {
        mapping aff = actual_rw["affinity"];
        foreach (string k, int v in aff) {
            who->add("affinity/" + k, v);
            tell_object(who, HIG "【傳承共鳴】" + k + " 道統傳承親和度提升了 " + sprintf("%d", v) + " 點！\n" NOR);
        }
    }
    if (actual_rw["items"]) {
        mixed itm = actual_rw["items"];
        string *item_list = ({});
        if (stringp(itm)) item_list = ({ itm });
        else if (arrayp(itm)) item_list = itm;

        foreach (string item_path in item_list) {
            object ob = clone_object(item_path);
            if (ob) {
                if ((ob->query("is_relic") || ob->query("is_road_pass")) && (present(ob->query_name(), who) || present("road pass", who))) {
                    destruct(ob);
                } else {
                    if (!ob->move(who)) ob->move(environment(who));
                    tell_object(who, HIG "【獲得獎勵物品：" + ob->query_short() + "】\n" NOR);
                }
            }
        }
    }
    if (actual_rw["msg"]) {
        tell_object(who, HIG + actual_rw["msg"] + "\n" NOR);
    }
}

// 檢查特定任務是否有遺失的信物 (支援 步驟層級、階段層級、任務頂層陣列)
mapping check_lost_item(object who, string qid) {
    if (!who || !quest_defs[qid]) return 0;
    mapping q = quest_defs[qid];
    int cur_step = query_quest_step(who, qid);
    if (cur_step <= 0) return 0;

    int cur_stage = query_quest_stage(who, qid);
    mixed *steps = query_stage_steps(q, cur_stage);

    // 1. 優先檢查當前步驟上的 lost_item_recovery
    if (arrayp(steps)) {
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
    }

    // 2. 檢查 Stage 層級的 lost_item_recovery
    mapping st_def = query_stage_def(q, cur_stage);
    if (st_def && arrayp(st_def["lost_item_recovery"])) {
        foreach (mapping rec in st_def["lost_item_recovery"]) {
            if (rec["item"] && !has_required_item(who, rec["item"])) {
                return rec;
            }
        }
    }

    // 3. 檢查任務頂層的 lost_item_recovery (如 rescue_miners.json)
    if (arrayp(q["lost_item_recovery"])) {
        foreach (mapping rec in q["lost_item_recovery"]) {
            if (rec["item"] && !has_required_item(who, rec["item"])) {
                return rec;
            }
        }
    }

    return 0;
}

// 專用信物丟失補領處理器 (全域掃描步驟級、階段級、頂層級遺失信物)
int check_and_handle_lost_item(object who, string npc_id, string topic) {
    if (!who || !npc_id) return 0;
    foreach (string qid, mapping q in quest_defs) {
        int cur_step = query_quest_step(who, qid);
        if (cur_step <= 0) continue;

        int cur_stage = query_quest_stage(who, qid);
        mixed *recs = ({});

        // 收集步驟層級
        mixed *steps = query_stage_steps(q, cur_stage);
        if (arrayp(steps)) {
            foreach (mapping s in steps) {
                if (s["step"] == cur_step && s["lost_item_recovery"]) {
                    recs += ({ s["lost_item_recovery"] });
                }
            }
        }

        // 收集 Stage 層級
        mapping st_def = query_stage_def(q, cur_stage);
        if (st_def && arrayp(st_def["lost_item_recovery"])) {
            recs += st_def["lost_item_recovery"];
        }

        // 收集頂層層級
        if (arrayp(q["lost_item_recovery"])) {
            recs += q["lost_item_recovery"];
        }

        foreach (mapping recovery in recs) {
            string req_item = recovery["item"] ? recovery["item"] : recovery["require_item"];
            if (req_item && req_item != "" && has_required_item(who, req_item)) {
                continue; // 身上已有，不重複補發
            }

            if (recovery["from_npc"] == npc_id || npc_id == "any") {
                if (!recovery["ask_topic"] || topic == recovery["ask_topic"] || topic == "任務" || topic == "信物") {
                    string reissue_path = recovery["reissue_item"];
                    if (reissue_path) {
                        object re_ob = clone_object(reissue_path);
                        if (re_ob) {
                            if (!re_ob->move(who)) re_ob->move(environment(who));
                            tell_object(who, HIY "\n" + recovery["dialogue"] + "\n" NOR);
                            tell_object(who, HIG "【你重新獲得了關鍵信物：" + re_ob->query_short() + "！】\n\n" NOR);
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

// ── 世界事件型任務階段檢定與因果結算橋接器 ────────────────────

int is_event_quest_stage_valid(mapping q) {
    if (!mapp(q) || !q["world_event"]) return 1;
    object em = load_object(EVENT_MANAGER_D);
    if (!em) return 1;

    string event_id = q["world_event"];
    string cur_stage = em->query_event_stage(event_id);
    string *valid_stages = em->query_valid_stages(event_id);
    int cur_idx = member_array(cur_stage, valid_stages);

    if (q["valid_stages"] && arrayp(q["valid_stages"])) {
        if (member_array(cur_stage, q["valid_stages"]) == -1) {
            return 0;
        }
    }
    if (q["deadline_stage"] && stringp(q["deadline_stage"])) {
        int dead_idx = member_array(q["deadline_stage"], valid_stages);
        if (dead_idx != -1 && cur_idx > dead_idx) {
            return 0;
        }
    }
    return 1;
}

mapping apply_world_event_outcome(object who, string qid, mapping q) {
    if (!who || !qid || !mapp(q) || !q["world_event"]) return ([]);
    object em = load_object(EVENT_MANAGER_D);
    if (!em) return ([]);

    string event_id = q["world_event"];
    mapping outcomes = q["event_outcomes"];
    if (!mapp(outcomes)) return ([]);

    // 動態評估成果等級 (Context-Dependent Grading，例如 B02 檢查 route_confidence)
    string selected_grade = "success";
    if (q["eval_metric"] && stringp(q["eval_metric"])) {
        int cur_val = em->query_metric(event_id, q["eval_metric"]);
        int req_min = q["eval_min_for_success"] ? q["eval_min_for_success"] : 1;
        if (cur_val < req_min && outcomes["partial"]) {
            selected_grade = "partial";
        }
    }

    mapping branch = outcomes[selected_grade];
    if (!mapp(branch)) branch = outcomes["success"];
    if (!mapp(branch)) return ([]);

    mapping payload = copy(branch);
    if (q["deadline_stage"]) payload["deadline_stage"] = q["deadline_stage"];
    if (q["valid_stages"]) payload["valid_stages"] = q["valid_stages"];

    string actor_id = who->query_key_id();
    if (!actor_id || actor_id == "") actor_id = "player";

    mapping res = em->apply_quest_outcome(event_id, qid, payload, actor_id);
    if (mapp(res)) {
        if (res["result"] == EVENT_RESULT_SUCCESS) {
            // 若有附加第二物證 (如 F03 同時登錄坩堝與雷管雙物證)，一併登錄至物證帳本
            if (mapp(branch["extra_evidence"]) && branch["extra_evidence"]["id"]) {
                em->register_evidence(branch["extra_evidence"]["id"], branch["extra_evidence"]);
            }
            who->set("quests/" + qid + "/outcome_grade", selected_grade);
            if (res["message"] && res["message"] != "") {
                tell_object(who, HIY "\n" + res["message"] + "\n" NOR);
            }
        } else if (res["result"] == EVENT_RESULT_DUPLICATE) {
            tell_object(who, CYN "\n【世界局勢】此項事件行動已由先行者達成，世界狀態不再重複疊加。\n" NOR);
        } else if (res["result"] == EVENT_RESULT_EXPIRED || res["result"] == EVENT_RESULT_REJECTED) {
            tell_object(who, HIR "\n【時機已逝】" + (res["message"] ? res["message"] : "世界時間軸已推進，該行動已逾越有效窗口！") + "\n" NOR);
        }
    }
    return res;
}

// ── 階段與任務結算處理器 (Stage / Quest Completion) ──────────

void handle_stage_completion(object who, string qid, mapping q, int cur_stage) {
    if (!who || !qid || !mapp(q)) return;

    mapping st_def = query_stage_def(q, cur_stage);
    int total_stages = (arrayp(q["stages"]) && sizeof(q["stages"]) > 0) ? sizeof(q["stages"]) : (q["total_stages"] ? q["total_stages"] : 1);

    // 發放該 Stage 的階段性獎勵 (調用統一獎勵發放器，相容 on_finish 與 rewards 宣告)
    if (st_def) {
        if (st_def["on_finish"]) {
            award_rewards(who, st_def["on_finish"], qid);
        } else if (st_def["rewards"]) {
            award_rewards(who, st_def["rewards"], qid);
        }
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
            // 直接解鎖下一 Stage / 環
            set_quest_stage(who, qid, cur_stage + 1);
            set_quest_step(who, qid, 1);
            set_quest_state(who, qid, "ACTIVE");
            who->set("quests/" + qid + "/progress/kill_count", 0);
            mapping next_st = query_stage_def(q, cur_stage + 1);
            string n_title = next_st ? next_st["title"] : "";
            string stage_label = (q["category"] == "hunting") ? ("第 " + sprintf("%d", cur_stage + 1) + " 環") : ("Stage " + sprintf("%d", cur_stage + 1));
            tell_object(who, HIY "\n【✨ 階梯晉級】" + stage_label + "試煉啟動：「" + n_title + "」！\n" NOR);
            mixed *next_steps = query_stage_steps(q, cur_stage + 1);
            if (sizeof(next_steps) > 0) {
                tell_object(who, HIG "  指引：" + next_steps[0]["hint"] + "\n\n" NOR);
            }
            return;
        }
    }

    // 若為全域世界事件任務，先行提交事務性因果結算
    if (q["world_event"]) {
        mapping ev_res = apply_world_event_outcome(who, qid, q);
        if (mapp(ev_res) && (ev_res["result"] == EVENT_RESULT_EXPIRED || ev_res["result"] == EVENT_RESULT_REJECTED)) {
            set_quest_step(who, qid, -1);
            set_quest_state(who, qid, "EXPIRED");
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
        if (qid == "village_pass") {
            who->set("quest/pass_village_ceremony", 1);
        }
    }

    // 發放最終任務獎勵 (調用統一獎勵發放器)
    if (q["rewards"]) {
        award_rewards(who, q["rewards"], qid);
    }

    tell_object(who, HIY "\n【✨ 恭喜完成歷練：「" + q["name"] + "」！】\n" NOR);
}

// ── 事件觸發與推進器 (Event Dispatcher) ─────────────────────

mixed trigger_event(object who, string event_type, mapping data) {
    if (!who || !mapp(data)) return 0;

    mixed raw_npc      = data["npc"];
    string npc_id      = stringp(raw_npc) ? raw_npc : "";
    string topic       = data["topic"];
    object item        = data["item"];
    string itm_id      = data["item_id"];
    if (!itm_id && item) itm_id = item->query_key_id();
    string itm_name    = data["item_name"];
    if (!itm_name && item) itm_name = item->query_name();
    string itm_file    = data["item_file"];
    if (!itm_file && item) itm_file = base_name(item);
    string verb        = data["verb"];
    string target      = data["target"];
    object npc_ob      = data["npc_obj"];
    object victim      = data["victim"];
    mixed raw_victim_id = data["victim_id"];
    string victim_id   = stringp(raw_victim_id) ? raw_victim_id : ((arrayp(raw_victim_id) && sizeof(raw_victim_id) > 0) ? raw_victim_id[0] : "");
    string victim_name = data["victim_name"];
    string victim_file = data["victim_file"];

    // 兩階段分派：第一輪優先推進已接取/進行中 (cur_step > 0) 的任務，避免未接取任務 (cur_step == 0) 的自動觸發搶佔已進行任務的事件
    for (int pass = 1; pass <= 2; pass++) {
    foreach (string qid, mapping q in quest_defs) {
        int cur_step = query_quest_step(who, qid);
        int cur_stage = query_quest_stage(who, qid);
        string q_state = query_quest_state(who, qid);

        if (pass == 1 && cur_step <= 0) continue;
        if (pass == 2 && cur_step != 0) continue;

        mixed *steps = query_stage_steps(q, cur_stage);
        if (!arrayp(steps) || sizeof(steps) == 0) continue;

        // 若當前 Stage 處於 DORMANT 狀態：檢查是否滿足下一 stage 的解鎖條件
        if (q_state == "DORMANT") {
            int next_stage_num = cur_stage + 1;
            mapping next_stage = query_stage_def(q, next_stage_num);
            if (next_stage) {
                // 檢查等級門檻
                int st_req_lvl = next_stage["required_level"];
                if (st_req_lvl > 0 && who->query_level() < st_req_lvl) {
                    mapping unl = next_stage["unlock_condition"];
                    if (event_type == "talk" && unl && unl["target_npc"] && 
                        npc_matches(unl["target_npc"], npc_id, npc_ob)) {
                        tell_object(who, HIR "【機緣隱伏】你尚未突破瓶頸（需要等級 " + sprintf("%d", st_req_lvl) + "），暫且無法參悟後續機緣。\n" NOR);
                        return 1;
                    }
                    continue;
                }

                mapping unlock = next_stage["unlock_condition"];
                int can_unlock = 0;
                if (unlock) {
                    if ((!unlock["need_stage"] || cur_stage >= unlock["need_stage"]) &&
                        unlock["target_npc"] && event_type == "talk" && 
                        npc_matches(unlock["target_npc"], npc_id, npc_ob) &&
                        topic_matches(unlock["target_topic"], topic)) {
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
            // 防護：非循環任務已完成不可重複接取
            if (q["type"] != "loop" && (who->query("quests/" + qid + "/state") == "COMPLETED" || who->query("quests/" + qid + "/state") == "EXPIRED")) {
                continue;
            }

            // 計算等級要求
            int req_level = 0;
            if (q["requirements"] && q["requirements"]["level"]) {
                req_level = q["requirements"]["level"];
            } else if (q["required_level"]) {
                req_level = q["required_level"];
            } else if (arrayp(q["stages"]) && sizeof(q["stages"]) > 0 && q["stages"][0]["required_level"]) {
                req_level = q["stages"][0]["required_level"];
            }

            // 方式 A: 向 start_npc 接取
            if (q["start_npc"] && event_type == "talk" && 
                npc_matches(q["start_npc"], npc_id, npc_ob) && 
                topic_matches(q["start_topic"], topic)) {

                if (q["world_event"] && !is_event_quest_stage_valid(q)) {
                    tell_object(who, HIR "【時機已逝】世界局勢已推進至新階段，【" + q["name"] + "】的行動窗口已關閉！\n" NOR);
                    return 1;
                }

                // 檢查等級條件
                if (req_level > 0 && who->query_level() < req_level) {
                    tell_object(who, HIR "【修為不足】這項歷練兇險異常，需要修為達到等級 " + sprintf("%d", req_level) + " 方可承接（當前等級：" + sprintf("%d", who->query_level()) + "）！\n" NOR);
                    return 1;
                }

                set_quest_stage(who, qid, 1);
                set_quest_step(who, qid, 1);
                set_quest_state(who, qid, "ACTIVE");
                tell_object(who, HIG "【接取歷練任務】" + q["name"] + "\n" +
                                     "  目標：" + steps[0]["hint"] + "\n" NOR);

                // 若首步即為向該 NPC 進行相同話題對話（例如 village_pass 或 fa_chain 第 1 步）：直接驗證並推進！
                mapping s0_talk = steps[0];
                if (s0_talk && s0_talk["target_type"] == "talk" && 
                    npc_matches(s0_talk["target_npc"], npc_id, npc_ob) && 
                    topic_matches(s0_talk["target_topic"], topic)) {
                    string req_item = s0_talk["require_item"];
                    if (!req_item || req_item == "" || has_required_item(who, req_item)) {
                        // 發放 step 1 完成回饋
                        if (s0_talk["on_complete"]) {
                            mapping oc0_talk = s0_talk["on_complete"];
                            if (oc0_talk["give_item"]) {
                                object r0_talk = clone_object(oc0_talk["give_item"]);
                                if (r0_talk) {
                                    if ((r0_talk->query("is_relic") || r0_talk->query("is_road_pass")) && (present(r0_talk->query_name(), who) || present("road pass", who))) {
                                        destruct(r0_talk);
                                    } else {
                                        if (!r0_talk->move(who)) r0_talk->move(environment(who));
                                        tell_object(who, HIG "【獲得信物：" + r0_talk->query_short() + "】\n" NOR);
                                    }
                                }
                            }
                            if (oc0_talk["msg"]) {
                                tell_object(who, HIG + oc0_talk["msg"] + "\n" NOR);
                            }
                        }

                        if (sizeof(steps) > 1) {
                            set_quest_step(who, qid, 2);
                            tell_object(who, HIG "【任務推進】第 2 步：" + steps[1]["hint"] + "\n\n" NOR);
                        } else {
                            handle_stage_completion(who, qid, q, cur_stage);
                        }
                    }
                }
                return 1;
            }

            // 方式 B: 隱藏奇遇或行為歷練在 step 1 透過 action 行為直接觸發接取
            mapping s0 = steps[0];
            if (s0["target_type"] == "action" && event_type == "action" && verb == s0["action_verb"]) {
                if (!s0["action_target"] || target == s0["action_target"]) {
                    // 地點檢定
                    string req_loc = s0["location"] ? s0["location"] : s0["room"];
                    if (req_loc && req_loc != "") {
                        object env = environment(who);
                        if (!env || strsrch(base_name(env), req_loc) == -1) {
                            continue;
                        }
                    }

                    if (q["world_event"] && !is_event_quest_stage_valid(q)) {
                        tell_object(who, HIR "【時機已逝】世界局勢已推進至新階段，【" + q["name"] + "】的行動窗口已關閉！\n" NOR);
                        return 0;
                    }

                    // 等級檢定
                    if (req_level > 0 && who->query_level() < req_level) {
                        tell_object(who, HIR "【修為不足】此處機緣暗伏，但你氣機尚未凝練（需要等級 " + sprintf("%d", req_level) + "），未能洞悉其中奧秘。\n" NOR);
                        return 0;
                    }

                    set_quest_stage(who, qid, 1);
                    set_quest_state(who, qid, "ACTIVE");
                    mapping st1 = query_stage_def(q, 1);
                    if (q["category"] == "epic") {
                        tell_object(who, HIY "\n【✨ 奇遇觸發・" + q["name"] + "】\n" NOR);
                        tell_object(who, CYN "你在這方邊陲之地觸動了失落的史前機緣，已踏上「Stage 1・" + (st1 ? st1["title"] : "始動") + "」！\n" NOR);
                    } else {
                        tell_object(who, HIY "\n【✨ 歷練開啟・" + q["name"] + "】\n" NOR);
                        tell_object(who, CYN "你在歷練之中有所體悟，已踏上「Stage 1・" + (st1 ? st1["title"] : "始動") + "」！\n" NOR);
                    }

                    // 發放 step 1 完成回饋
                    if (s0["on_complete"]) {
                        mapping oc0 = s0["on_complete"];
                        if (oc0["give_item"]) {
                            object r0 = clone_object(oc0["give_item"]);
                            if (r0) {
                                if ((r0->query("is_relic") || r0->query("is_road_pass")) && (present(r0->query_name(), who) || present("road pass", who))) {
                                    destruct(r0);
                                } else {
                                    if (!r0->move(who)) r0->move(environment(who));
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

            // 方式 C: 戰鬥觸發任務 (首步為 kill 類型且無 start_npc)
            mapping s0_kill = steps[0];
            if (!q["start_npc"] && s0_kill["target_type"] == "kill" && event_type == "kill") {
                string target_mob = s0_kill["target_mob"] ? s0_kill["target_mob"] : (s0_kill["target_npc"] ? s0_kill["target_npc"] : s0_kill["target"]);
                int mob_matched = 0;
                if (target_mob && target_mob != "") {
                    if (victim && (victim->id(target_mob) || (victim_id != "" && victim_id == target_mob) || victim->query_name() == target_mob)) {
                        mob_matched = 1;
                    } else if (victim_file && strsrch(victim_file, target_mob) != -1) {
                        mob_matched = 1;
                    } else if (target_mob == "zhao si" && ((victim_name && strsrch(victim_name, "趙四") != -1) || (victim_file && strsrch(victim_file, "zhao") != -1))) {
                        mob_matched = 1;
                    }
                }
                if (mob_matched) {
                    string req_loc = s0_kill["location"] ? s0_kill["location"] : s0_kill["room"];
                    if (req_loc && req_loc != "") {
                        object env = environment(who);
                        if (!env || strsrch(base_name(env), req_loc) == -1) {
                            continue;
                        }
                    }

                    if (req_level > 0 && who->query_level() < req_level) {
                        tell_object(who, HIR "【修為不足】你氣機尚未凝練（需要等級 " + sprintf("%d", req_level) + "），未能洞悉此戰牽連的驚天陰謀。\n" NOR);
                        continue;
                    }

                    set_quest_stage(who, qid, 1);
                    set_quest_state(who, qid, "ACTIVE");
                    mapping st1 = query_stage_def(q, 1);
                    tell_object(who, HIY "\n【✨ 歷練開啟・" + q["name"] + "】\n" NOR);
                    tell_object(who, CYN "你在這方邊陲之地踏破迷局，已踏上「Stage 1・" + (st1 ? st1["title"] : "始動") + "」！\n" NOR);

                    if (s0_kill["on_complete"]) {
                        mapping oc0_kill = s0_kill["on_complete"];
                        if (oc0_kill["msg"]) {
                            tell_object(who, HIG + oc0_kill["msg"] + "\n" NOR);
                        }
                    }

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
            if (npc_matches(recovery["from_npc"], npc_id, npc_ob) && 
                (topic_matches(recovery["ask_topic"], topic) || topic == "任務" || topic == "信物")) {
                string reissue_path = recovery["reissue_item"];
                if (reissue_path) {
                    object re_ob = clone_object(reissue_path);
                    if (re_ob) {
                        if (!re_ob->move(who)) re_ob->move(environment(who));
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

            // 地點檢驗 (若步驟定義了 location / room)
            string s_loc = s["location"] ? s["location"] : s["room"];
            if (s_loc && s_loc != "") {
                object cur_env = environment(who);
                if (!cur_env || strsrch(base_name(cur_env), s_loc) == -1) {
                    continue; // 地點不符，不推進
                }
            }

            int matched = 0;
            string t_type = s["target_type"];

            // A. 對話類步驟 (talk)
            if (t_type == "talk" && event_type == "talk") {
                if (npc_matches(s["target_npc"], npc_id, npc_ob) && 
                    topic_matches(s["target_topic"], topic)) {
                    string req = s["require_item"];
                    if (!req || req == "" || has_required_item(who, req)) {
                        matched = 1;
                    } else {
                        tell_object(who, HIR "你身上似乎缺少了對話所需的關鍵信物！\n" NOR);
                    }
                }
            }
            // B. 交付類步驟 (deliver)
            else if (t_type == "deliver" && event_type == "deliver") {
                if (npc_matches(s["target_npc"], npc_id, npc_ob)) {
                    string req = s["require_item"];
                    int item_matched = 0;
                    if (!req || req == "") {
                        item_matched = 1;
                    } else {
                        if (item) {
                            if (item->id(req) || item->query("is_" + req) || item->query("herb_type") == req) item_matched = 1;
                            if (item->id(replace_string(req, "_", " "))) item_matched = 1;
                            if (replace_string(req, "_", "") == "orechunk" && (item->id("ore") || item->query("is_ore"))) item_matched = 1;
                        }
                        if (!item_matched && itm_id && (itm_id == req || itm_id == replace_string(req, "_", " "))) item_matched = 1;
                        if (!item_matched && itm_file && (strsrch(itm_file, req) != -1 || strsrch(itm_file, replace_string(req, " ", "_")) != -1)) item_matched = 1;
                        if (!item_matched && itm_name && strsrch(itm_name, req) != -1) item_matched = 1;
                    }
                    if (item_matched) {
                        matched = 1;
                    }
                }
            }
            // C. 行動類步驟 (action)
            else if (t_type == "action" && event_type == "action") {
                if (verb == s["action_verb"]) {
                    if (!s["action_target"] || target == s["action_target"]) {
                        // 裝備檢定
                        string req_eq = s["require_equipped"];
                        if (req_eq && req_eq != "") {
                            int has_eq = 0;
                            object weapon = who->query_temp("weapon");
                            if (weapon && (weapon->id(req_eq) || strsrch(base_name(weapon), req_eq) != -1)) {
                                has_eq = 1;
                            }
                            if (!has_eq && has_required_item(who, req_eq)) {
                                has_eq = 1;
                            }
                            if (!has_eq) {
                                tell_object(who, HIR "你尚未裝備或手持執行此動作所需的道具【" + req_eq + "】！\n" NOR);
                                break;
                            }
                        }

                        // 背包道具檢定
                        string req_inv = s["require_inventory"] ? s["require_inventory"] : s["require_item"];
                        if (req_inv && req_inv != "") {
                            if (!has_required_item(who, req_inv)) {
                                tell_object(who, HIR "你身上缺少執行此動作所需的關鍵道具【" + req_inv + "】！\n" NOR);
                                break;
                            }
                        }

                        // 消耗品扣除
                        string con_item = s["consume_item"];
                        if (con_item && con_item != "") {
                            object *inv = all_inventory(who);
                            object con_ob = 0;
                            foreach (object o in inv) {
                                if (o->id(con_item) || strsrch(base_name(o), con_item) != -1) {
                                    con_ob = o;
                                    break;
                                }
                            }
                            if (con_ob) {
                                tell_object(who, HIY "【消耗了 " + con_ob->query_short() + "】\n" NOR);
                                destruct(con_ob);
                            }
                        }

                        matched = 1;
                    }
                }
            }
            // D. 擊殺類步驟 (kill)
            else if (t_type == "kill" && event_type == "kill") {
                string target_mob = s["target_mob"] ? s["target_mob"] : (s["target_npc"] ? s["target_npc"] : s["target"]);
                int mob_matched = 0;
                if (target_mob && target_mob != "") {
                    if (victim && (victim->id(target_mob) || (victim_id != "" && victim_id == target_mob) || victim->query_name() == target_mob)) {
                        mob_matched = 1;
                    } else if (victim_file && strsrch(victim_file, target_mob) != -1) {
                        mob_matched = 1;
                    } else if (target_mob == "wolf" && ((victim_name && strsrch(victim_name, "狼") != -1) || (victim_file && strsrch(victim_file, "wolf") != -1))) {
                        mob_matched = 1;
                    } else if (target_mob == "zhao si" && ((victim_name && strsrch(victim_name, "趙四") != -1) || (victim_file && strsrch(victim_file, "zhao") != -1))) {
                        mob_matched = 1;
                    } else if ((target_mob == "mine_rat" || target_mob == "rat") && ((victim_name && strsrch(victim_name, "鼠") != -1) || (victim_file && strsrch(victim_file, "rat") != -1))) {
                        mob_matched = 1;
                    } else if ((target_mob == "wild_bear" || target_mob == "bear") && ((victim_name && strsrch(victim_name, "熊") != -1) || (victim_file && strsrch(victim_file, "bear") != -1))) {
                        mob_matched = 1;
                    }
                }

                if (mob_matched) {
                    // 防重計：同一個怪物死亡事件不重計
                    if (victim && victim->query_temp("counted_for_" + qid)) {
                        break;
                    }
                    if (victim) {
                        victim->set_temp("counted_for_" + qid, 1);
                    }

                    int req_cnt = s["required_count"] ? s["required_count"] : 1;
                    if (req_cnt > 1) {
                        int cur_cnt = who->query("quests/" + qid + "/progress/kill_count");
                        cur_cnt++;
                        if (cur_cnt < req_cnt) {
                            who->set("quests/" + qid + "/progress/kill_count", cur_cnt);
                            tell_object(who, HIG "【任務進度】" + q["name"] + "（" + s["title"] + "）：" + sprintf("%d / %d", cur_cnt, req_cnt) + "\n" NOR);
                            return 1;
                        } else {
                            who->delete("quests/" + qid + "/progress/kill_count");
                            matched = 1;
                        }
                    } else {
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
                                if (!reward_ob->move(who)) reward_ob->move(environment(who));
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

    // 2. 多階段史詩/奇遇任務 或 階梯狩獵任務 (以 Stage/環 為宏觀單位)
    if (arrayp(q["stages"]) && sizeof(q["stages"]) > 0) {
        int total_st = sizeof(q["stages"]);
        int is_hunting = (q["category"] == "hunting");
        string state_badge = "";
        if (q_state == "DORMANT") {
            state_badge = YEL " [Stage " + sprintf("%d", cur_stage) + " 達成・靜候天時]" NOR;
        } else if (q_state == "COMPLETED") {
            state_badge = HIG " [全線圓滿]" NOR;
        } else if (cur_step > 0) {
            state_badge = is_hunting ? HIY " [第 " + sprintf("%d/%d", cur_stage, total_st) + " 環 進行中]" NOR : HIY " [Stage " + sprintf("%d/%d", cur_stage, total_st) + " 進行中]" NOR;
        } else {
            state_badge = WHT " [未觸發]" NOR;
        }

        string out = sprintf(HIW "【%s】" NOR "%s\n", q["name"], state_badge);

        for (int i = 0; i < total_st; i++) {
            mapping st_def = q["stages"][i];
            int s_num = st_def["stage"];
            string st_title = st_def["title"];
            string region = st_def["region_name"] ? st_def["region_name"] : st_def["region"];
            string st_prefix = is_hunting ? ("第 " + sprintf("%d", s_num) + " 環") : ("Stage " + sprintf("%d", s_num));

            if (cur_step == 0) {
                out += sprintf(CYN "  [ ] %s：%s (%s)\n" NOR, st_prefix, st_title, region);
            } else if (s_num < cur_stage || (s_num == cur_stage && q_state == "DORMANT")) {
                out += sprintf(HIG "  [✓] %s：%s (%s - 已完成)\n" NOR, st_prefix, st_title, region);
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
                out += sprintf(HIY "  [▶] %s：%s (%s - 進行中)\n" NOR, st_prefix, st_title, region);
                mixed *st_steps = st_def["steps"];
                if (arrayp(st_steps)) {
                    for (int j = 0; j < sizeof(st_steps); j++) {
                        mapping ss = st_steps[j];
                        int ss_num = ss["step"];
                        if (cur_step > ss_num) {
                            out += sprintf(HIG "      [✓] 第 %d 步：%s\n" NOR, ss_num, ss["title"]);
                        } else if (cur_step == ss_num) {
                            string progress_info = "";
                            if (ss["target_type"] == "kill" && ss["required_count"] > 1) {
                                int cur_k = who->query("quests/" + qid + "/progress/kill_count");
                                progress_info = sprintf(" (進度: %d / %d)", cur_k, ss["required_count"]);
                            }
                            out += sprintf(HIY "      [▶] 第 %d 步：%s (進行中%s)\n" NOR, ss_num, ss["title"], progress_info);
                            out += sprintf(WHT "          指引：%s\n" NOR, ss["hint"]);

                            mapping lost_rec = check_lost_item(who, qid);
                            if (lost_rec) {
                                out += sprintf(HIR "          ⚠️ 身上缺少關鍵信物，可前往向【%s】詢問「%s」補領！\n" NOR,
                                              lost_rec["from_npc"], lost_rec["ask_topic"]);
                            }
                        } else {
                            out += sprintf(GRN "      [ ] 第 %d 步：%s\n" NOR, ss_num, ss["title"]);
                        }
                    }
                }
            } else {
                out += sprintf(WHT "  [ ] %s：%s (待解鎖・需前往 %s)\n" NOR, st_prefix, st_title, region);
            }
        }
        return out;
    }

    // 3. 一般單階支線/主線/循環生計
    string round_info = "";
    if (q["type"] == "loop") {
        int r = query_quest_rounds(who, qid);
        string status_note = (r >= 6 ? "・保底物資" : (r > 3 ? "・收益遞減" : "・全額收益"));
        round_info = sprintf(" (已完成: %d 輪%s)", r, status_note);
    }
    string out = sprintf(HIW "【%s】" NOR "%s\n", q["name"], round_info);
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
            string progress_info = "";
            if (s["target_type"] == "kill" && s["required_count"] > 1) {
                int cur_k = who->query("quests/" + qid + "/progress/kill_count");
                progress_info = sprintf(" (進度: %d / %d)", cur_k, s["required_count"]);
            }
            out += sprintf(HIY "  [▶] 第 %d 步：%s (進行中%s)\n" NOR, s_idx, s["title"], progress_info);
            out += sprintf(WHT "      指引：%s\n" NOR, s["hint"]);

            mapping lost_rec = check_lost_item(who, qid);
            if (lost_rec) {
                out += sprintf(HIR "      ⚠️ 身上缺少關鍵信物，可前往向【%s】詢問「%s」補領！\n" NOR,
                              lost_rec["from_npc"], lost_rec["ask_topic"]);
            }
        } else {
            out += sprintf(GRN "  [ ] 第 %d 步：%s\n" NOR, s_idx, s["title"]);
        }
    }
    return out;
}

// 產生所有任務的總覽面板 (四方聚合：道統歷練、聚落主線、獵戶進階、生計委託、史詩奇遇)
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

    // 2. 聚落主線歷練
    string *main_list = ({ "cycle_of_craft", "rescue_maiden", "rescue_miners", "village_pass" });
    int has_main = 0;
    foreach (string qid in main_list) {
        if (quest_defs[qid]) {
            int step = who->query("quests/" + qid + "/step");
            string st = who->query("quests/" + qid + "/state");
            if (step > 0 || st == "COMPLETED") {
                if (!has_main) {
                    out += HIG "---------------- 聚落主線歷練 ----------------\n" NOR;
                    has_main = 1;
                }
                out += query_quest_checklist(who, qid) + "\n";
            }
        }
    }

    // 3. 大荒獵戶進階令
    string *hunting_list = ({ "hunting_chain" });
    int has_hunting = 0;
    foreach (string qid in hunting_list) {
        if (quest_defs[qid]) {
            int step = who->query("quests/" + qid + "/step");
            string st = who->query("quests/" + qid + "/state");
            if (step > 0 || st == "COMPLETED") {
                if (!has_hunting) {
                    out += MAG "---------------- 大荒獵戶進階令 ----------------\n" NOR;
                    has_hunting = 1;
                }
                out += query_quest_checklist(who, qid) + "\n";
            }
        }
    }

    // 4. 日常生計委託 (支援收益遞減)
    string *loop_list = ({ "mining_loop", "herb_loop", "pelt_loop" });
    int has_loop = 0;
    foreach (string qid in loop_list) {
        if (quest_defs[qid]) {
            int step = who->query("quests/" + qid + "/step");
            int r = who->query("quests/" + qid + "/rounds");
            if (step > 0 || r > 0) {
                if (!has_loop) {
                    out += YEL "---------------- 日常生計委託 ----------------\n" NOR;
                    has_loop = 1;
                }
                out += query_quest_checklist(who, qid) + "\n";
            }
        }
    }

    // 5. 江湖支線委託
    string *side_list = ({ "wolf_hunter" });
    int has_side = 0;
    foreach (string qid in side_list) {
        if (quest_defs[qid]) {
            int step = who->query("quests/" + qid + "/step");
            string st = who->query("quests/" + qid + "/state");
            if (step > 0 || st == "COMPLETED") {
                if (!has_side) {
                    out += CYN "---------------- 江湖支線委託 ----------------\n" NOR;
                    has_side = 1;
                }
                out += query_quest_checklist(who, qid) + "\n";
            }
        }
    }

    // 6. 史詩奇遇與長線隱藏線索
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

    // 7. 大荒煞潮・生存事件網 (Phase 1 MVP 8 大標竿任務)
    string *event_list = ({
        "A01_dead_gazelle", "A02_reverse_tracks", "B02_rockfall_diversion",
        "C01_grain_inventory", "D01_last_painkiller", "E01_street_defense",
        "G01_palisade_breach", "F03_testimony_cross_check"
    });
    int has_event_q = 0;
    foreach (string qid in event_list) {
        if (quest_defs[qid]) {
            int step = who->query("quests/" + qid + "/step");
            string st = who->query("quests/" + qid + "/state");
            if (step > 0 || st == "COMPLETED" || st == "EXPIRED") {
                if (!has_event_q) {
                    object em = load_object(EVENT_MANAGER_D);
                    string stg = em ? em->query_event_stage(EVENT_BEAST_SURGE) : "T-3";
                    out += HIR "---------------- 大荒煞潮・生存事件網 (當前階段: " + stg + ") ----------------\n" NOR;
                    has_event_q = 1;
                }
                out += query_quest_checklist(who, qid) + "\n";
            }
        }
    }

    out += HIW "======================================================\n" NOR;
    return out;
}

