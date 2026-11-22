// d/yunjin/dock_coolie_lane.c
// 雲津城・碼頭苦力算帳棚（Tier 2 冰河苦力結算工籌與烘靴暖棚）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津碼頭・苦力算帳棚");
    set_long("冰河木筏碼頭東側搭著厚氈布的木頭工棚，棚裡燒著兩盆旺火炭盆，上頭烤著\n"
             "一排排濕漉漉的羊皮水靴與麻布護膝。幾名碼頭苦力排隊拿著竹製「扛木籌子」找管事\n"
             "核對今日搬運凍紅杉的次數 (tally chips)，防止黑心包頭私吞工錢。\n"
             "向西跨過結霜木梯即回【雲津城・冰河木筏碼頭】。\n");

    set_exits(([
        "west": "/d/yunjin/river_wharf.c",
    ]));

    set("is_outdoor", 0);
    set("no_combat", 1);

    set_touch("default", YEL "炭盆邊烘烤的羊皮靴帶著潮氣與溫熱，手中竹籌邊緣被手指搓得油滑。" NOR);
    set_smell("default", YEL "炭火焙乾濕羊皮的淡淡膻氣、凍泥味與熱菜湯的樸實煙火味。" NOR);
    set_listen("default", WHT "算盤珠劈啪連響，夾著苦力漢子粗聲大氣核對竹籌數目的爭執與笑聲。" NOR);

    mapping tally_rule = ([
        "targets": ({ "chips", "ledger", "木籌", "對帳", "" }),
        "sp_cost": 5,
        "sensory_msg": YEL "你幫幾名不識字的碼頭苦力把竹籌與貨棧水單一筆一筆核對清楚，替大夥少扣了十幾文黑心錢。" NOR,
        "train_stat": ([ "int": 8, "per": 6 ]),
        "exp_gain": 12,
        "quest_verb": "tally",
        "quest_target": "chips"
    ]);
    add_action_rule("tally", tally_rule);
    add_action_rule("對籌", tally_rule);

    spawn_npc("/clone/npc/folk/county_worker.c");
}
