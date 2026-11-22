// d/village/smokehouse_shed.c
// 黑石鋪・山麓烘肉寮（非修仙向的山民冬儲燻肉與獸夾修整點）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("黑石鋪・山麓烘肉寮");
    set_long("緊鄰獵戶哨亭東側的一座低矮石砌燻房，屋頂留著排煙的木瓦天窗。\n"
             "屋裡挖著兩口深地灶，上頭架著幾層燻得烏黑油亮的青岡木椽子，掛滿了\n"
             "抹好粗鹽與花椒準備過冬的野兔乾與山豬肋條 (meat)。牆角還靠著幾副待修\n"
             "的生鏽鐵獸夾與備用麻繩。\n"
             "向西穿過籬笆小門即回【林邊茅屋・獵戶哨亭】。\n");

    set_exits(([
        "west": "/d/village/hunter_cabin.c",
    ]));

    set("is_outdoor", 0);
    set("no_combat", 1);

    set_touch("default", YEL "燻肉木椽溫熱滑膩、摸一手陳年煙油，牆角的鐵獸夾冰冷沉重且帶著鐵鏽。" NOR);
    set_smell("default", HIR "濃郁醇厚的青岡木與濕柏葉燻煙味，夾著花椒、粗鹽與臘肉滴油的焦香。" NOR);
    set_listen("default", WHT "地灶底暗火「滋滋」烤著油脂，偶爾傳來屋簷山雀試探啄食的輕響。" NOR);

    mapping cure_rule = ([
        "targets": ({ "meat", "臘肉", "燻肉", "" }),
        "sp_cost": 8,
        "sensory_msg": YEL "你拿長木叉翻轉椽上掛著的鹹肉，再往地灶添上一把濕柏葉，燻煙均勻地滲入肉理之中。" NOR,
        "train_stat": ([ "con": 6, "dex": 6 ]),
        "exp_gain": 8
    ]);
    add_action_rule("cure", cure_rule);
    add_action_rule("燻肉", cure_rule);

    spawn_npc("/clone/npc/folk/qian_trapper.c");
}
