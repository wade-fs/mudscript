// /d/routes/forest_sea_post.c
// 東線第二段 (seg_city_panmu, 260里) 節點 1：南嶺林海驛・巨木轉運站

#include "/include/ansi.h"
#include "/include/globals.h"

inherit ROUTE_ROOM_OB;

void create() {
    ::create();
    set_route_segment("seg_city_panmu");
    set_node_index(1);
    set_short("南嶺林海驛・巨木轉運站");
    set_long("這裡是盤木縣北上金石府城的南嶺林海官道主驛。高聳入雲的古冷杉與鐵木\n"
             "遮天蔽日，寬達三丈的碎石官道上絡繹不絕地行駛著滿載巨木與熟革的八方鏢車。\n"
             "驛站旁設有大型飲馬水槽與吊裝滾木的滑車架。往南即返【盤木縣北門】，向北則\n"
             "進入地勢漸陡的【林道滑坡搶通段】。\n");

    set_exits(([
        "south": "/d/counties/panmu/north_gate.c",
        "north": "/d/routes/forest_landslide.c",
    ]));

    set_coordinate(3, 8, 0);

    mapping fire_rule = ([
        "targets": ({ "fire", "hearth", "篝火", "借火", "" }),
        "sp_cost": 6,
        "sensory_msg": HIY "你掏出防水松脂火摺引燃乾燥杉針，替受寒的官道趕路車夫重新點起一盆劈啪作響的旺火，驅散山林寒霧。" NOR,
        "train_stat": ([ "dex": 6, "sen": 6 ]),
        "exp_gain": 10,
        "quest_verb": "kindle",
        "quest_target": "fire"
    ]);
    add_action_rule("kindle", fire_rule);
    add_action_rule("借火", fire_rule);
}
