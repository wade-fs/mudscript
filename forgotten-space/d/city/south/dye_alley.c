// d/city/south/dye_alley.c
// 金石城南・染坊與布莊窄巷（Tier 1 民間手工業日常）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石城南・染坊窄巷");
    set_long("這條被數十匹晾曬藍印花布與粗麻布遮得半明半暗的長巷，地面青石板常年被\n"
             "溢出的板藍根靛藍染水潑得發青。幾名染工光著手臂在冒熱氣的大木染缸邊來回絞布 (dye)，\n"
             "巷口裁縫鋪裡則掛著尋常百姓穿的粗布短衫與棉布圍裙。\n"
             "向東走出高掛布幡的巷口即回【金石老酒肆】。\n");

    set_exits(([
        "east": "/d/city/south/wine_tavern.c",
    ]));

    set("is_outdoor", 1);
    set("no_combat", 1);

    set_touch("default", CYN "濕漉漉的青石路面微滑冰涼，半乾粗麻布面在風裡甩打手臂粗糙而涼爽。" NOR);
    set_smell("default", HIG "濃重微苦的板藍根草靛發酵味、皂角灰水氣與曬乾棉布的日光清香撲鼻而來。" NOR);
    set_listen("default", CYN "染布進缸的「噗通」水聲、絞布木棒擰轉的嘎吱聲與風拂布匹的獵獵響動。" NOR);

    mapping dye_rule = ([
        "targets": ({ "cloth", "dye", "染布", "布匹", "" }),
        "sp_cost": 8,
        "sensory_msg": CYN "你替染工扛起木槓把兩匹浸滿靛藍染汁的粗麻布絞乾上竿晾曬，手掌染上淡淡青色卻覺得格外踏實。" NOR,
        "train_stat": ([ "str": 6, "dex": 6 ]),
        "exp_gain": 10
    ]);
    add_action_rule("dye", dye_rule);
    add_action_rule("晾布", dye_rule);

    spawn_npc("/clone/npc/folk/county_worker.c");
}
