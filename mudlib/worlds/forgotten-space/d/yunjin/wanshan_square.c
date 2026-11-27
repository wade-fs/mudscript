// /d/yunjin/wanshan_square.c
// 雲津仙集・萬山廣場 (Ch.84-85：萬山靈石票牌價板與三宗山門分流樞紐)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津仙集・萬山廣場");
    set_long("三宗交匯之雲津盆地心臟，青石板路面被地底分支火脈烘得微濕。\n"
             "廣場中央矗立著一面烏木牌價板，明碼標示「萬山靈石票」與「三宗外門供奉額」折算牌價。\n"
             "四方通衢：北面踏階直上【石牌坊與問道天台】（northup），正北通【太清登天雲梯山門】，西北往【八荒萬鈞問心谷】，\n"
             "東北赴【丹鼎百草丹門】，正東往【天工千鍛百巧門】，東南入【商埠公所】與【雲海票號】，正西入【西街貨棧區】。\n");

    set_exits(([
        "south":     "/d/yunjin/north_road_gate.c",
        "northup":   "/d/yunjin/stone_arch_quarantine.c",
        "southeast": "/d/yunjin/public_office.c",
        "west":      "/d/yunjin/western_warehouse_street.c",
        "north":     "/d/sects/taiqing/gate.c",
        "northwest": "/d/sects/bahuang/gate.c",
        "east":      "/d/sects/tiangong/gate.c",
        "northeast": "/d/sects/danding/gate.c",
        "southwest": "/d/yunjin/river_wharf.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", YEL "青石板路面被地底火脈烘得微微發溫，踩上去竟不覺得如城外那般刺骨陰寒。" NOR);
    set_smell("default", YEL "烤羊湯、熱磚茶、硫磺礦砂與三宗弟子袍袖上的淡淡丹藥香在廣場上空交織。" NOR);
    set_listen("default", HIY "萬山靈石票牌價板前商販喊價聲、雪橇鈴鐺聲與四方山門傳來的鐘磬聲熱鬧鼎沸。" NOR);

    mapping board_rule = ([
        "targets": ({ "board", "prices", "牌價", "牌價板", "" }),
        "sp_cost": 2,
        "sensory_msg": HIY "你擠過圍觀商販細看烏木牌價板上的今日靈石票折算牌價，對雲津仙集近來的物資緊俏心裡有了底。" NOR,
        "train_stat": ([ "int": 6 ]),
        "exp_gain": 6
    ]);
    add_action_rule("browse", board_rule);
    add_action_rule("看牌價", board_rule);

    spawn_npc("/clone/npc/folk/route_traveler.c");
}
