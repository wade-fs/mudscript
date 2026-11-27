// d/sects/tiangong/apprentice_shed.c
// 天工門・雜役磨件棚（Tier 2 機關宗門底層學徒打磨日常）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("天工門・雜役磨件棚");
    set_long("天工門外牆根下搭著一長溜油布防雨鐵棚，裡面支著十二台腳踏水磨石砂輪與生鐵虎鉗。\n"
             "剛入門的雜役弟子還摸不到精巧的墨斗陣圖，每天只對著成筐冷鑄青銅齒輪與鐵軸承做枯燥的手工去毛邊、\n"
             "倒角與校平，指腹包著厚厚一層滲油紗布。\n"
             "向南穿過齒輪拱門即是【千機大廳】。\n");

    set_exits(([
        "south": "/d/sects/tiangong/thousand_mechanisms_hall.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", WHT "夾在生鐵虎鉗上的青銅齒輪冷硬冰手，細鐵銼刀把柄纏著吸滿機油與汗水的粗麻布。" NOR);
    set_smell("default", YEL "金屬細粉塵、火油冷卻液與粗糙砂輪磨擦出的淡淡焦味混在一起。" NOR);
    set_listen("default", WHT "「沙——沙——」幾十支鐵銼齊刷刷來回銼磨金屬毛刺，伴隨著水磨石輪低沉的嗡鳴。" NOR);

    mapping polish_rule = ([
        "targets": ({ "gear", "part", "齒輪", "零件", "" }),
        "sp_cost": 10,
        "sensory_msg": WHT "你把一枚剛出模的青銅齒輪夾緊虎鉗，拿細紋平銼按固定角度一銼一銼修去齒槽毛邊，齒面漸漸亮如明鏡。" NOR,
        "train_stat": ([ "dex": 10, "per": 8 ]),
        "exp_gain": 14,
        "quest_verb": "polish",
        "quest_target": "gear"
    ]);
    add_action_rule("polish", polish_rule);
    add_action_rule("打磨", polish_rule);

    spawn_npc("/clone/npc/folk/county_worker.c");
}
