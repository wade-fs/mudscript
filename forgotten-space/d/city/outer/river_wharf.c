// d/city/outer/river_wharf.c
// 青河入城・外城貨運碼頭（Tier 1 城市水上生計支翼：漕船卸貨、木筏與纖夫日常）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("青河入城・外城貨運碼頭");
    set_long("一條沿著青河下游護城河開鑿出來的寬闊木樁碼頭，十幾艘吃水深沉的平底糧船與原木木排正繫纜靠岸。\n"
             "光著膀子、肩披粗麻墊肩的腳夫正喊著整齊低沉的號子，踩著晃悠悠的跳板扛卸米袋與松木料。\n"
             "碼頭邊支著兩口大鐵鍋熬著免費供給力夫的濃薑湯，蒸騰起帶著腥甜河泥味的白霧。\n"
             "向東走下礫石河灘是熱鬧叫賣的【外城河埠魚市】，向南跨過青石引橋即入城內【西水門漕運碼頭】。\n");

    set_exits(([
        "south": "/d/city/south/canal.c",
        "east":  "/d/city/outer/fish_market.c",
    ]));

    set("is_outdoor", 1);
    set("no_combat", 1);

    set_touch("default", CYN "濕漉漉的杉木跳板表面啃出了密密麻麻的防滑鑿痕，粗麻纜繩摩擦著掌心粗糙發熱。" NOR);
    set_smell("default", YEL "濃郁的青河水腥氣、新伐濕松木脂香與大鍋熬薑湯的辛辣白霧撲面而來。" NOR);
    set_listen("default", WHT "「嘿喲——起！」船工號子壓過了木船吱嘎撞擊橡膠護樁的悶響與河水拍岸聲。" NOR);

    mapping unload_rule = ([
        "targets": ({ "sack", "cargo", "米袋", "木料", "" }),
        "sp_cost": 10,
        "sensory_msg": YEL "你往肩頭墊起一塊粗麻墊肩，踩穩晃動的木跳板一口氣扛下兩袋百斤稻米，汗水順著鎖骨滴在碼頭木板上。" NOR,
        "train_stat": ([ "str": 10, "con": 10 ]),
        "exp_gain": 12,
        "quest_verb": "unload",
        "quest_target": "wharf"
    ]);
    add_action_rule("unload", unload_rule);
    add_action_rule("扛包", unload_rule);

    spawn_npc("/clone/npc/folk/county_worker.c");
}
