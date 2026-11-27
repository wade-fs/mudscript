// /daemon/tier3_d.c
// 第四卷 Tier 3 桃花源洞天底層規則守護進程 (TIER3_D)
// 核心職責：
// 1. 單一可調表 (tier3_tuning)：集中管理舊招三倍高耗、半威力、U 路徑成本、洞天跨界時差倍率與高代價雙向信標門檻
// 2. K × U 能力驗證：禁止以計數旗標冒充認知/運用，必須透過「可驗證環境實驗」寫入 K，再經兩條以上觀察路徑之一解鎖 U
// 3. 高代價雙向信標檢定：嚴禁活體傳送、嚴限半斤載重、強制消耗三百斤鹽晶儲柱與特鍛黑鐵導波環
// 4. CROSS-05 與 Tier 4 區隔：嚴禁完成 Tier 3 校準事件即自動解鎖 /d/secret/ (須滿足 §4.2 三要件)

#include "/include/ansi.h"
#include "/include/globals.h"
#include "/include/world_event.h"

inherit "/std/object.c";

mapping tier3_tuning;
mapping domain_specs;

void init_tuning_and_specs();

void create() {
    ::create();
    init_tuning_and_specs();
}

void init_tuning_and_specs() {
    // ── 單一可調表：集中管理三倍高耗、半威力、U 路徑成本、時差倍率與信標門檻 ──
    tier3_tuning = ([
        "old_skill_cost_mult" : 3,
        "old_skill_power_pct" : 50,
        "u_skill_cost_pct"    : 100,
        "u_skill_power_pct"   : 100,
        "realm_time_ratio"    : 12, // 跨界時差倍率：洞天 1 日 ≈ 人間 12 日 (Ch.144~167: 洞天90日大校準 vs 人間三年整)
        "beacon" : ([
            "salt_crystal_jin"    : 300,
            "conduit_rings"       : 1,
            "max_weight_liang"    : 5,
            "window_breaths"      : 3,
            "allow_living_transit": 0
        ])
    ]);

    // ── 五大領域 K（可驗證環境實驗）× U（雙觀察路徑解鎖）規格 ──
    domain_specs = ([
        "law" : ([
            "combat_path" : "fa",
            "k_name"      : "大氣幾何張力認知",
            "u_name"      : "無星向量牽引",
            "u_cost_note" : "測算過載易引發左目雪盲殘影與指節微顫",
            "k_experiments" : ([
                "measure_basalt_wind" : ([
                    "desc"          : "以測量銅尺與炭筆夜測玄武岩風砂軌跡與底層頻率夜飄",
                    "required_keys" : ({ "copper_ruler_drift", "dust_vector_trace" })
                ]),
                "inspect_taixu_steps" : ([
                    "desc"          : "於白玉升空階座實測星盤壓迫傾角",
                    "required_keys" : ({ "step_incline_angle", "salt_resonance_delta" })
                ])
            ]),
            "u_paths" : ([
                "wind_sand_copper_ruler" : ([
                    "name"           : "野測風砂銅尺路徑（Ch.131）",
                    "required_proof" : ({ "tangent_sketch", "low_cost_barrier_test" }),
                    "cost_pct"       : 90
                ]),
                "taixu_calibration_log" : ([
                    "name"           : "校星院日誌交叉實證路徑（Ch.135–136）",
                    "required_proof" : ({ "heng_log_diff", "reverse_star_alignment" }),
                    "cost_pct"       : 90
                ])
            ])
        ]),
        "force" : ([
            "combat_path" : "li",
            "k_name"      : "戰祖裂谷重力衰減節律認知",
            "u_name"      : "無聲截息穿貫",
            "u_cost_note" : "箭矢磨損劇烈，右肩舊傷限制高重力連射上限",
            "k_experiments" : ([
                "time_gravity_pulse" : ([
                    "desc"          : "藉戰神圖騰共振測算裂谷重力沉降與衰減半拍間隔",
                    "required_keys" : ({ "pulse_interval_beats", "totem_resonance" })
                ]),
                "track_scorch_prey" : ([
                    "desc"          : "於焦土邊界追蹤灰甲砂蜥與荒獸避壓步頻",
                    "required_keys" : ({ "prey_stride_cadence", "recoil_damping_ratio" })
                ])
            ]),
            "u_paths" : ([
                "totem_gravity_pulse" : ([
                    "name"           : "圖騰共振實戰截息路徑（Ch.139–140）",
                    "required_proof" : ({ "half_beat_release", "bone_mane_kill" }),
                    "cost_pct"       : 100
                ]),
                "veteran_hunter_marks" : ([
                    "name"           : "燕山鷹記與骨哨換氣傳授路徑（Ch.133/140）",
                    "required_proof" : ({ "eagle_mark_rubbing", "pack_breath_cadence" }),
                    "cost_pct"       : 100
                ])
            ])
        ]),
        "craft" : ([
            "combat_path" : "wu",
            "k_name"      : "標準活榫應力分散構型認知",
            "u_name"      : "可拆換多向活榫鍛法",
            "u_cost_note" : "受限於太古焊料存量，每兩時辰須停爐自然散熱",
            "k_experiments" : ([
                "disassemble_salt_casing" : ([
                    "desc"          : "以精鋼分寸卡尺拆檢報廢鹽晶蓄能柱鎖死銅鎖結構",
                    "required_keys" : ({ "tolerance_gap", "slag_clog_site" })
                ]),
                "audit_wanwu_scrap_axle" : ([
                    "desc"          : "檢修萬物外環運料車軸卡死公差",
                    "required_keys" : ({ "axle_play_mm", "sleeve_heat_limit" })
                ])
            ]),
            "u_paths" : ([
                "removable_stove_build" : ([
                    "name"           : "灰燼石堡換芯暖爐實作路徑（Ch.132）",
                    "required_proof" : ({ "tenon_prototype", "three_day_burn_verify" }),
                    "cost_pct"       : 95
                ]),
                "wanwu_scrap_bench" : ([
                    "name"           : "萬物外環齊九軸試工核驗路徑（Ch.137）",
                    "required_proof" : ({ "qi_bench_pass", "modular_joint_sample" }),
                    "cost_pct"       : 95
                ])
            ])
        ]),
        "medicine" : ([
            "combat_path" : "",
            "k_name"      : "異律排異結晶病理認知",
            "u_name"      : "環境相容緩衝針法",
            "u_cost_note" : "無法逆轉徹底石化骨骼，過度接觸晶塵易留掌心硬斑",
            "k_experiments" : ([
                "compare_three_pole_samples" : ([
                    "desc"          : "對照太虛玉屑、萬物浸液、戰祖獸血與地煞血精頻譜差",
                    "required_keys" : ({ "taixu_dust", "wanwu_sludge", "zhanzu_blood" })
                ])
            ]),
            "u_paths" : ([
                "clinic_three_pole_samples" : ([
                    "name"           : "邊緣診所三極樣本配伍路徑（Ch.141）",
                    "required_proof" : ({ "bitter_moss_ratio", "bone_needle_insulation" }),
                    "cost_pct"       : 100
                ]),
                "patient_crystal_autopsy" : ([
                    "name"           : "石堡病例簿與晶化鹽夫臨床路徑（Ch.130）",
                    "required_proof" : ({ "ledger_review", "cold_compress_trial" }),
                    "cost_pct"       : 100
                ])
            ])
        ]),
        "commerce" : ([
            "combat_path" : "",
            "k_name"      : "三極供應鏈瓶頸與配額總帳認知",
            "u_name"      : "跨極資源槓桿與停工制裁網",
            "u_cost_note" : "依賴實物準備金與公開帳本，失算即面臨武力清零",
            "k_experiments" : ([
                "audit_salt_market_deficit" : ([
                    "desc"          : "核對殘晶黑市預扣三成戰備折抵與七成抽成實帳",
                    "required_keys" : ({ "levy_pct", "buyback_drop_pct" })
                ])
            ]),
            "u_paths" : ([
                "nine_city_quota_ledger" : ([
                    "name"           : "九城離線配額總帳補冊路徑（Ch.142–143）",
                    "required_proof" : ({ "registered_households", "labor_salt_offset" }),
                    "cost_pct"       : 100
                ]),
                "three_pole_labor_compact" : ([
                    "name"           : "三極工役互助密約串聯路徑（Ch.145–146）",
                    "required_proof" : ({ "twenty_four_stations", "twelve_salt_sheds" }),
                    "cost_pct"       : 100
                ])
            ])
        ])
    ]);
}

mapping query_tuning() {
    return copy(tier3_tuning);
}

int set_tuning_value(string key, mixed val) {
    if (!key || key == "") return 0;
    if (member_array(key, keys(tier3_tuning)) == -1) return 0;
    tier3_tuning[key] = val;
    return 1;
}

// ── 跨界時差倍率與時間換算介面 (Ch.144~167：洞天 90 日 ≈ 人間 3 年整，倍率 12:1) ──
int query_realm_time_ratio() {
    if (!tier3_tuning || undefinedp(tier3_tuning["realm_time_ratio"])) return 12;
    int r = tier3_tuning["realm_time_ratio"];
    return r > 0 ? r : 12;
}

mapping query_realm_time_conversion(int realm_days) {
    int ratio = query_realm_time_ratio();
    int mortal_days = realm_days * ratio;
    return ([
        "realm_days"          : realm_days,
        "mortal_days"         : mortal_days,
        "mortal_years_approx" : mortal_days / 365,
        "ratio"               : ratio
    ]);
}

mapping query_calibration_cycle_info() {
    int ratio = query_realm_time_ratio();
    int realm_cycle_years = (ratio > 0) ? (300 / ratio) : 25;
    return ([
        "realm_time_ratio"                  : ratio,
        "novel_canon_basis"                 : "Ch.144~167: 洞天90日 ≈ 人間3年整 (1095日，倍率12:1)",
        "calibration_countdown_realm_days"  : 90,
        "calibration_countdown_mortal_years": 3,
        "calibration_cycle_mortal_years"    : 300,
        "calibration_cycle_realm_years"     : realm_cycle_years,
        "rule_summary"                      : sprintf("洞天 1 日 ≈ 人間 %d 日；人間三百年大校準，洞天每 %d 年一輪元", ratio, realm_cycle_years)
    ]);
}

// 推進洞天時間，同時依跨界倍率 (12:1) 同步推進人間日曆
void advance_realm_time(int realm_minutes) {
    if (realm_minutes <= 0) return;
    int ratio = query_realm_time_ratio();
    object nature_d = find_object(NATURE_D);
    if (!nature_d) nature_d = load_object(NATURE_D);
    if (nature_d) {
        nature_d->advance_time(realm_minutes * ratio);
    }
}

// 取得特定對象或環境之有效時間流速比例 (凡間 4:1，洞天 48:1)
int query_effective_time_ratio(mixed target) {
    int base_ratio = 4;
    object nature_d = find_object(NATURE_D);
    if (!nature_d) nature_d = load_object(NATURE_D);
    if (nature_d) base_ratio = nature_d->query_time_ratio();

    if (!target) return base_ratio;
    object env = 0;
    if (objectp(target)) {
        env = environment(target);
        if (!env) env = target;
    }
    if (env && is_tier3_environment(env)) {
        return base_ratio * query_realm_time_ratio();
    }
    return base_ratio;
}

mapping query_domain_spec(string domain) {
    if (!domain || !domain_specs[domain]) return ([]);
    return copy(domain_specs[domain]);
}

string path_to_domain(string combat_path) {
    if (combat_path == "fa") return "law";
    if (combat_path == "li") return "force";
    if (combat_path == "wu") return "craft";
    return "";
}

int is_tier3_environment(object room) {
    if (!room) return 0;
    string fname = base_name(room);
    if (!fname) return 0;
    return (strsrch(fname, REALM_DIR) == 0);
}

int has_k(object me, string domain) {
    if (!me || !domain || !domain_specs[domain]) return 0;
    mixed k = me->query("tier3_k/" + domain);
    // 禁止以純整數計數或裸字串冒充能力旗標：必須為經過環境實驗驗證的結構化 mapping
    if (!mapp(k)) return 0;
    if (!stringp(k["exp_id"]) || k["exp_id"] == "") return 0;
    if (!domain_specs[domain]["k_experiments"][k["exp_id"]]) return 0;
    if (!mapp(k["evidence"]) || sizeof(k["evidence"]) == 0) return 0;
    return 1;
}

int has_u(object me, string domain) {
    if (!has_k(me, domain)) return 0;
    mixed u = me->query("tier3_u/" + domain);
    if (!mapp(u)) return 0;
    if (!stringp(u["path_id"]) || u["path_id"] == "") return 0;
    if (!domain_specs[domain]["u_paths"][u["path_id"]]) return 0;
    return 1;
}

int has_u_for_path(object me, string combat_path) {
    string dom = path_to_domain(combat_path);
    if (dom == "") return 0;
    return has_u(me, dom);
}

// ── 寫入 K：必須通過已註冊的可驗證環境實驗 ────────────────────────
mapping grant_k_from_experiment(object me, string domain, string exp_id, mapping evidence) {
    if (!me || !domain || !domain_specs[domain]) {
        return ([ "ok": 0, "reason": "unknown_domain" ]);
    }
    mapping exps = domain_specs[domain]["k_experiments"];
    if (!exp_id || !exps[exp_id]) {
        return ([ "ok": 0, "reason": "unregistered_experiment" ]);
    }
    if (!mapp(evidence)) {
        return ([ "ok": 0, "reason": "evidence_must_be_structured" ]);
    }
    string *req = exps[exp_id]["required_keys"];
    foreach (string rk in req) {
        if (undefinedp(evidence[rk]) || !evidence[rk]) {
            return ([ "ok": 0, "reason": "missing_experiment_evidence:" + rk ]);
        }
    }

    mapping record = ([
        "domain"      : domain,
        "exp_id"      : exp_id,
        "desc"        : exps[exp_id]["desc"],
        "evidence"    : copy(evidence),
        "verified_at" : time()
    ]);
    me->set("tier3_k/" + domain, record);
    return ([ "ok": 1, "domain": domain, "exp_id": exp_id, "k_name": domain_specs[domain]["k_name"] ]);
}

// ── 解鎖 U：必須先具 K，並通過該領域任意一條註冊觀察路徑 ─────────────
mapping unlock_u_via_path(object me, string domain, string path_id, mapping proof) {
    if (!me || !domain || !domain_specs[domain]) {
        return ([ "ok": 0, "reason": "unknown_domain" ]);
    }
    if (!has_k(me, domain)) {
        return ([ "ok": 0, "reason": "missing_verified_k" ]);
    }
    mapping upaths = domain_specs[domain]["u_paths"];
    if (!path_id || !upaths[path_id]) {
        return ([ "ok": 0, "reason": "unregistered_u_path" ]);
    }
    if (!mapp(proof)) {
        return ([ "ok": 0, "reason": "proof_must_be_structured" ]);
    }
    string *req = upaths[path_id]["required_proof"];
    foreach (string rp in req) {
        if (undefinedp(proof[rp]) || !proof[rp]) {
            return ([ "ok": 0, "reason": "missing_u_proof:" + rp ]);
        }
    }

    mapping u_rec = ([
        "domain"      : domain,
        "path_id"     : path_id,
        "path_name"   : upaths[path_id]["name"],
        "u_name"      : domain_specs[domain]["u_name"],
        "cost_pct"    : upaths[path_id]["cost_pct"],
        "cost_note"   : domain_specs[domain]["u_cost_note"],
        "proof"       : copy(proof),
        "unlocked_at" : time()
    ]);
    me->set("tier3_u/" + domain, u_rec);
    return ([ "ok": 1, "domain": domain, "path_id": path_id, "u_name": domain_specs[domain]["u_name"] ]);
}

// ── 戰鬥與技藝消耗／威力計算（供 COMBAT_D 呼叫） ────────────────────
int query_effective_skill_cost(object me, string combat_path, int base_cost) {
    if (base_cost <= 0) return 0;
    if (!me || !environment(me) || !is_tier3_environment(environment(me))) {
        return base_cost;
    }
    string dom = path_to_domain(combat_path);
    if (dom == "") return base_cost;

    if (!has_u(me, dom)) {
        int mult = tier3_tuning["old_skill_cost_mult"];
        if (mult < 1) mult = 3;
        return base_cost * mult;
    }

    mapping u_rec = me->query("tier3_u/" + dom);
    int pct = (mapp(u_rec) && u_rec["cost_pct"] > 0) ? u_rec["cost_pct"] : tier3_tuning["u_skill_cost_pct"];
    int eff = base_cost * pct / 100;
    if (eff < 1) eff = 1;
    return eff;
}

int query_effective_power_pct(object me, string combat_path) {
    if (!me || !environment(me) || !is_tier3_environment(environment(me))) {
        return 100;
    }
    string dom = path_to_domain(combat_path);
    if (dom == "") return 100;

    if (!has_u(me, dom)) {
        int pct = tier3_tuning["old_skill_power_pct"];
        if (pct <= 0) pct = 50;
        return pct;
    }
    return tier3_tuning["u_skill_power_pct"];
}

// ── 高代價雙向微光信標檢定 (Ch.165–167) ────────────────────────────
mapping transmit_beacon_parcel(object me, mapping parcel) {
    if (!me || !mapp(parcel)) {
        return ([ "ok": 0, "reason": "invalid_parcel" ]);
    }
    mapping bcfg = tier3_tuning["beacon"];
    if (parcel["is_living"] && !bcfg["allow_living_transit"]) {
        return ([
            "ok"     : 0,
            "reason" : "living_transit_forbidden",
            "msg"    : "三息微光信標裂隙極窄，嚴禁活人肉身強渡，強闖必遭空間撕碎！"
        ]);
    }
    int weight = parcel["weight_liang"];
    if (weight <= 0 || weight > bcfg["max_weight_liang"]) {
        return ([
            "ok"     : 0,
            "reason" : "overweight_limit",
            "msg"    : sprintf("信標總載重嚴限半斤（%d 兩）以內，當前 %d 兩超重將震碎導波環！", bcfg["max_weight_liang"], weight)
        ]);
    }
    int salt_jin = parcel["salt_crystal_jin"];
    int rings = parcel["conduit_rings"];
    if (salt_jin < bcfg["salt_crystal_jin"]) {
        return ([
            "ok"     : 0,
            "reason" : "insufficient_salt_crystal",
            "msg"    : sprintf("啟動信標須一次燒盡 %d 斤高純導流鹽晶儲柱（目前僅備 %d 斤）。", bcfg["salt_crystal_jin"], salt_jin)
        ]);
    }
    if (rings < bcfg["conduit_rings"]) {
        return ([
            "ok"     : 0,
            "reason" : "missing_conduit_ring",
            "msg"    : sprintf("啟動信標需消耗 %d 具特鍛黑鐵導波環。", bcfg["conduit_rings"])
        ]);
    }

    int sent_count = me->query("tier3_beacon_sent") + 1;
    me->set("tier3_beacon_sent", sent_count);
    me->set("tier3_last_beacon", ([
        "title"         : parcel["title"] ? parcel["title"] : "雲津微光家書囊",
        "weight_liang"  : weight,
        "salt_consumed" : bcfg["salt_crystal_jin"],
        "ring_consumed" : bcfg["conduit_rings"],
        "window_breaths": bcfg["window_breaths"],
        "sent_at"       : time()
    ]));

    return ([
        "ok"             : 1,
        "salt_consumed"  : bcfg["salt_crystal_jin"],
        "ring_consumed"  : bcfg["conduit_rings"],
        "window_breaths" : bcfg["window_breaths"],
        "sent_count"     : sent_count
    ]);
}

// ── Tier 4 (/d/secret/) 解鎖門檻檢定 (CROSS-05 ＋ traceability §4.2) ─
mapping evaluate_tier4_unlock_eligibility(object me) {
    if (!me) return ([ "eligible": 0, "reason": "no_actor" ]);

    int has_fusion    = me->query("enc_map_fusion") ? 1 : 0;
    int has_resonance = me->query("three_yuan_resonance") ? 1 : 0;
    int has_pierced   = me->query("personal_event/pierced_false_heaven") ? 1 : 0;

    string *missing = ({});
    if (!has_fusion) missing += ({ "enc_map_fusion" });
    if (!has_resonance) missing += ({ "three_yuan_resonance" });
    if (!has_pierced) missing += ({ "personal_event/pierced_false_heaven" });

    int eligible = (sizeof(missing) == 0) ? 1 : 0;
    return ([
        "eligible"              : eligible,
        "tier3_calibration_done": me->query("event_honors/" + EVENT_TIER3_CALIBRATION) ? 1 : 0,
        "tier3_beacon_sent"     : me->query("tier3_beacon_sent") ? 1 : 0,
        "missing_requirements"  : missing,
        "reason"                : eligible ? "tier4_requirements_met" : "tier4_requires_tri_criteria"
    ]);
}
