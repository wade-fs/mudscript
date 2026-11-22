// d/city/outer/tenement_alley.c
// 金石南關外・流民賃居矮巷（Tier 1 城市底層生活支翼：無路引苦力與流民互助）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("南關外・流民賃居矮巷");
    set_long("這條緊貼金石南城牆根外側的潮濕土坯矮巷，擠滿了用舊木板、油氈布與破草蓆搭成的簡陋棚屋。\n"
             "來自六縣的失地流民、跛腳老車夫與幫工婦人在此合租落腳，盼著天亮前去城門外接幾趟苦力散活。\n"
             "屋簷下晾著打滿補丁的粗布短褂，角落幾口小泥爐裡燒著拾來的煤核與枯枝，正燉著稀薄菜粥。\n"
             "往東穿過土坯矮牆缺口即是【南關官道】，那裡有通往南關城門的驛路。\n");

    set_exits(([
        "east": "/d/city/outer/south_road.c",
    ]));

    set("is_outdoor", 1);
    set("no_combat", 1);

    set_touch("default", WHT "潮濕陰涼的城牆磚石與粗糙土坯牆縫裡夾著發霉草繩與陳年泥灰的濕氣。" NOR);
    set_smell("default", YEL "低廉蜂窩煤灰、水煮白菜湯氣與潮濕粗布衣物混合出沉重而真實的底層煙火味。" NOR);
    set_listen("default", WHT "巷底傳來低沉咳嗽聲、木輪手推車軸的吱呀聲，以及城內打更人遙遠模糊的梆子聲。" NOR);

    mapping help_rule = ([
        "targets": ({ "wood", "stove", "coal", "木柴", "泥爐", "" }),
        "sp_cost": 5,
        "sensory_msg": YEL "你蹲下身替幾戶孤寡流民把濕透的煤核掰開添進小泥爐裡，火星劈啪竄起，泥屋裡總算多了幾分暖意。" NOR,
        "train_stat": ([ "con": 6, "per": 6 ]),
        "exp_gain": 8,
        "quest_verb": "tend_stove",
        "quest_target": "alley"
    ]);
    add_action_rule("stoke", help_rule);
    add_action_rule("添火", help_rule);

    spawn_npc("/clone/npc/folk/sun_old_carter.c");
}
