// /d/yunjin/hearing_hall.c
// 問道天台・雲頂三宗論道會武高台暨公開質證席（Ch.112, Ch.116-117）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("問道天台・雲頂三宗質證高台");
    set_long("高懸雲津仙集上方雲海邊緣的巨大平頂石坪，方圓數百丈，四周環立二十四根刻滿\n"
             "太清星宿、八荒戰紋與千機齒輪的合抱石柱；底下正是壓著太清百年祕密的護山大陣樞紐。\n"
             "北側鋪著青紫錦緞的高台上並肩端坐三宗掌門（紫霄真人、鐵背山主、玄樞門主）與五方查核席，\n"
             "台下石階坐滿近三千名內外門弟子與商會代表。向東入【東西百工丹器雙試台】，\n"
             "向西入【北側力法演武台】，向北臨【半山結晶毒域救援區】，向南下返【石牌坊迎風口】。\n");

    set_exits(([
        "southdown": "/d/yunjin/stone_arch_quarantine.c",
        "east":      "/d/yunjin/tournament_craft_arena.c",
        "west":      "/d/yunjin/tournament_combat_arena.c",
        "north":     "/d/yunjin/crystal_poison_edge.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", HIW "雲海邊緣的高台青石已被山風吹得冷硬刺骨，合抱石柱刻痕深處隱隱透出大陣震動。" NOR);
    set_smell("default", HIC "萬丈高空的清冽雪霧氣息、香案松煙味與三宗代表齊聚的緊繃火藥氣。" NOR);
    set_listen("default", HIY "數千名門人與商會代表在台階下屏息低語，山風捲過二十四根星宿石柱發出嗡嗡長鳴。" NOR);

    spawn_npc("/clone/npc/zixiao_zhenren.c");
    spawn_npc("/clone/npc/tiebei_shanzhu.c");
    spawn_npc("/clone/npc/xuanshu_menzhu.c");
}
