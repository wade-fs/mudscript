// /d/wastes/north_road/qing_pass.c
// 北境官道・青石埡口 (Ch.83-84：俯瞰雲津峽谷與三大名山輪廓)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("北境官道・青石埡口");
    set_long("翻過這道覆滿積雪的青石高埡，兩側千仞絕壁瞬間替行人擋住了外荒暴風。\n"
             "極目遠眺，三座通天名山鼎足環抱著下方雲海峽谷盆地：北側雲頂天柱峰紫霄\n"
             "隱現、西北大黑山黑雲壓城、東側萬仞天工山吞吐地肺白煙。\n"
             "往南可返【斷崖石棚驛站】，順緩坡向北下行十餘里即達【雲津仙集・北境商旅入口】。\n");

    set_exits(([
        "south": "/d/wastes/north_road/post_station.c",
        "north": "/d/yunjin/north_road_gate.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", WHT "高埡青石表面覆滿半融厚雪，扶著崖壁粗石能感到背風一側明顯暖和許多。" NOR);
    set_smell("default", CYN "背後仍是荒原飛雪的乾冷氣息，前方峽谷卻隱約飄上地肺白煙與市井炊煙味。" NOR);
    set_listen("default", HIC "風聲在過了高埡後驟然減弱，隱約能聽見山下雲津盆地傳來的市集鼓聲與車馬喧嘩。" NOR);

    mapping view_rule = ([
        "targets": ({ "basin", "mountains", "盆地", "三山", "" }),
        "sp_cost": 4,
        "sensory_msg": HIC "你站在青石埡口極目遠眺，紫霄、大黑山與萬仞天工山鼎足而立的雄姿盡收眼底，胸臆頓寬。" NOR,
        "train_stat": ([ "spi": 6, "per": 6 ]),
        "exp_gain": 10
    ]);
    add_action_rule("lookout", view_rule);
    add_action_rule("遠眺", view_rule);

    spawn_npc("/clone/npc/folk/route_traveler.c");
}
