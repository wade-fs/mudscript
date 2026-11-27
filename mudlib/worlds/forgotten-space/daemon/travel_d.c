// /daemon/travel_d.c
// 六縣與黑石鋪全域路網通行與季節阻斷守護進程 (Regional Travel Daemon)
// 依據 CITY_D 之 12 條標準路段 (ROUTE_SEGMENTS) 與 NATURE_D 四季氣候進行通行檢核、精力消耗與敘事日數累計

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/object.c";

void create() {
    ::create();
}

// 檢核指定角色以特定交通方式 (foot / fast_horse / heavy_wagon / water_barge) 通行某路段的合法性與成本
mapping check_segment_traversal(object who, string seg_id, string mode) {
    object city_d = load_object(CITY_D);
    if (!city_d) return ([ "allowed": 0, "reason": "no_city_d", "msg": "都城路網守護進程未載入。" ]);

    mapping seg = city_d->query_route_segment(seg_id);
    if (!mapp(seg)) {
        return ([ "allowed": 0, "reason": "unknown_segment", "msg": "未知的標準交通路段：" + (seg_id ? seg_id : "null") ]);
    }

    if (!mode || mode == "") {
        if (who && who->query_temp("travel_mode")) {
            mode = who->query_temp("travel_mode");
        } else {
            mode = "foot";
        }
    }

    // 1. 交通載具與地形硬性限制
    if (mode == "heavy_wagon" && seg["heavy_wagon_days"] == 0) {
        return ([
            "allowed": 0,
            "reason": "heavy_wagon_forbidden",
            "seg_id": seg_id,
            "mode": mode,
            "msg": sprintf("【路網限制】%s（%s）地形險峻，嚴禁重型大車通行！", seg["name"], seg["normal_duration"])
        ]);
    }

    if (mode == "fast_horse" && seg["fast_horse_shichen"] == 0) {
        return ([
            "allowed": 0,
            "reason": "fast_horse_forbidden",
            "seg_id": seg_id,
            "mode": mode,
            "msg": sprintf("【路網限制】%s（%s）為水路或地下暗河，無法騎乘快馬通行！", seg["name"], seg["normal_duration"])
        ]);
    }

    // 2. 四季氣候與季節性封閉判定
    string season = "autumn";
    if (who && who->query_temp("override_season") && who->query_temp("override_season") != "") {
        season = who->query_temp("override_season");
    } else {
        object nat_d = load_object("/secure/nature_d.c");
        if (nat_d) season = nat_d->query_season();
    }

    mapping s_limits = seg["seasonal_limits"];
    string warning = "";
    int sp_mult = 1;

    if (mapp(s_limits) && s_limits[season]) {
        warning = s_limits[season];

        // 季節性完全阻斷路段
        if (seg_id == "seg_city_qinghe_water" && season == "summer") {
            return ([
                "allowed": 0,
                "reason": "seasonal_block",
                "season": season,
                "seg_id": seg_id,
                "msg": "【季節阻斷】" + warning + "，青河水關已下令全面封航！"
            ]);
        }
        if (seg_id == "seg_city_zhuoshui_under" && season == "summer") {
            return ([
                "allowed": 0,
                "reason": "seasonal_block",
                "season": season,
                "seg_id": seg_id,
                "msg": "【季節阻斷】" + warning + "，地下溶洞暗河已被湍急洪水徹底淹沒！"
            ]);
        }
        if (seg_id == "seg_blackstone_zhongshi" && (season == "summer" || season == "winter")) {
            return ([
                "allowed": 0,
                "reason": "seasonal_block",
                "season": season,
                "seg_id": seg_id,
                "msg": "【季節阻斷】" + warning + "，落龍西谷懸崖棧道無法通行，請改走東線虎跳峽林道！"
            ]);
        }
        if (seg_id == "seg_city_zhenfeng" && season == "winter" && mode == "heavy_wagon") {
            return ([
                "allowed": 0,
                "reason": "seasonal_heavy_wagon_block",
                "season": season,
                "seg_id": seg_id,
                "msg": "【季節阻斷】" + warning + "，重載車隊無法翻越天風谷積雪！"
            ]);
        }

        // 非完全阻斷但具季節損耗加倍（如夏歲紅石斷脈地火暑熱、冬春虎跳峽凍融泥石等）
        sp_mult = 2;
    }

    // 3. 計算精力 (sp) 消耗與敘事行程日數
    int dist = seg["distance_li"];
    int base_sp = dist / 25;
    if (base_sp < 4) base_sp = 4;
    int sp_cost = base_sp * sp_mult;

    int narrative_days = seg["foot_days"];
    if (mode == "heavy_wagon") {
        narrative_days = seg["heavy_wagon_days"];
    } else if (mode == "fast_horse" && seg["fast_horse_shichen"] > 0) {
        narrative_days = (seg["fast_horse_shichen"] + 11) / 12;
    }

    return ([
        "allowed": 1,
        "seg_id": seg_id,
        "name": seg["name"],
        "distance_li": dist,
        "mode": mode,
        "season": season,
        "sp_cost": sp_cost,
        "sp_mult": sp_mult,
        "narrative_days": narrative_days,
        "seasonal_warning": warning,
        "msg": warning != "" ? ("【氣候警示】" + warning) : "路況正常，可順利通行。"
    ]);
}

// 執行路段跋涉結算：扣除精力並累計角色敘事行程日數與總里程
mapping record_segment_traversal(object who, string seg_id, string mode) {
    mapping res = check_segment_traversal(who, seg_id, mode);
    if (!res["allowed"] || !who) return res;

    int cur_sp = who->query("sp");
    int cost = res["sp_cost"];
    if (cur_sp > cost) {
        who->set("sp", cur_sp - cost);
    } else {
        who->set("sp", 1);
    }

    int old_days = who->query("travel_narrative_days");
    int old_li   = who->query("travel_distance_li");
    who->set("travel_narrative_days", old_days + res["narrative_days"]);
    who->set("travel_distance_li", old_li + res["distance_li"]);

    return res;
}
