// /d/wastes/expedition_camp.c
// 北荒裂谷深處三百里・冰脊高地勘探大營（Ch.104, Ch.110-111）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("北荒裂谷・冰脊高地勘探大營");
    set_long("深入裂谷三百餘里的高寒冰脊營地，黑山營重甲親兵於正營壓陣，赤煉先遣隊重車\n"
             "數日前卻假借「探測東側深層冰脈」悄悄轉往三十里外。子時過後避開巡夜燈籠可往\n"
             "西北摸上【裂谷觀測斷崖】，正西接隱蔽冰槽通往【冰谷窄口】，向南退回【永凍血原】。\n");

    set_exits(([
        "south":     "/d/wastes/frozen_blood_plain.c",
        "northwest": "/d/wastes/rift_watch.c",
        "west":      "/d/wastes/ice_valley_exit.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", HIW "冰脊高地凍土堅逾生鐵，帳篷防風繩結著一指厚的硬冰碴，摸上去刺骨麻木。" NOR);
    set_smell("default", CYN "凜冽稀薄的極寒雪氣裡夾著一絲營地炭盆餘煙與重車防滑油氣。" NOR);
    set_listen("default", WHT "高空冰風如刀割過營帳帆布發出「獵獵」哀鳴，遠處冰縫偶爾傳來地層裂響。" NOR);

    mapping lookout_rule = ([
        "targets": ({ "tracks", "camp", "轍印", "營地", "" }),
        "sp_cost": 6,
        "sensory_msg": CYN "你伏低身子察看營地邊緣重車雪橇偏離主道的深轍，暗暗記下三十里外東側冰脈的方位。" NOR,
        "train_stat": ([ "per": 8 ]),
        "exp_gain": 10
    ]);
    add_action_rule("inspect", lookout_rule);
    add_action_rule("察轍", lookout_rule);
}
