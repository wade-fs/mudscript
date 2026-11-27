// /d/counties/qinghe/ferry_dock.c
// 青河縣 (Qinghe County) 房間 2/14：漕運平底駁船碼頭 (對應卷二 Ch.58-59)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("qinghe");
    set_short("青河縣・漕運駁船碼頭");
    set_long("寬闊的青石碼頭階梯一直延伸入碧綠的青河水中，數十艘特製的寬體平底\n"
             "漕船正排隊裝載烘乾裝箱的洗靈草、苦參與今年新收的秋稻。碼頭立著一根刻有紅白\n"
             "水尺的量水石柱，水行船夫們正焦急地盯著水尺刻度議論上游水勢。往北登岸回\n"
             "【東迎水陸關門】，向東順流駛入【九曲淺灘】（300 里水路），往西南沿河岸可抵【蘆花渡】。\n");

    set_stage_desc(1, "上游定神道觀私自下放攔水石閘兩尺，碼頭水位明顯下降，重載糧船吃水吃緊。");
    set_stage_desc(2, "碼頭水行船夫與道觀護院發生爭執，平底漕船因淺灘擱淺被迫延誤船期！");
    set_stage_desc(3, "上游攔水壩淤沙潰漫，渾濁泥水湧入碼頭，靈草外銷全面封鎖，藥價飆漲！");
    set_stage_desc(4, "商會青河分號出資炸開副渠洩水，水位雖已恢復，但四成靈草已被商會預先壟斷。");

    set_exits(([
        "north":     "/d/counties/qinghe/east_gate.c",
        "east":      "/d/routes/qinghe_shallow_bend.c",
        "southwest": "/d/counties/qinghe/luhuadu_dock.c",
    ]));

    set_coordinate(-7, 9, 0);

    mapping gauge_rule = ([
        "targets": ({ "gauge", "pillar", "水尺", "水勢", "" }),
        "sp_cost": 5,
        "sensory_msg": CYN "你沿濕滑青石階梯蹲到河邊，借著水紋仔細讀出紅白水尺上的吃水刻度——水位雖淺，平底小藥船尚可勉力出港。" NOR,
        "train_stat": ([ "per": 8 ]),
        "exp_gain": 10,
        "quest_verb": "check_gauge",
        "quest_target": "gauge"
    ]);
    add_action_rule("check_gauge", gauge_rule);
    add_action_rule("量水尺", gauge_rule);

    mapping repair_rule = ([
        "targets": ({ "mooring", "post", "纜樁", "木樁", "" }),
        "sp_cost": 10,
        "sensory_msg": CYN "你涉著沒過腳踝的冷河水，用浸過桐油的新麻繩將鬆動的橡木纜樁死死綁緊並打入兩根鐵楔，渡口泊位頓時牢靠許多。" NOR,
        "train_stat": ([ "str": 10, "con": 8 ]),
        "exp_gain": 14,
        "quest_verb": "repair",
        "quest_target": "mooring"
    ]);
    add_action_rule("repair", repair_rule);
    add_action_rule("搶修", repair_rule);

    spawn_npc("/clone/npc/folk/qinghe_herb_woman.c");
}
