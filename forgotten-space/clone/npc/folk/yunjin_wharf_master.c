// clone/npc/folk/yunjin_wharf_master.c
// 雲津城・冰河船把頭（北境商貿冰水碼頭日常與船工生計）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("冰河船把頭");
    set_short(HIW "披霜戴雪" NOR " 冰河船把頭");
    set_long("一位披著羊皮破襖、濃眉結著白霜的北方老船夫。\n"
             "他左手少了兩根指頭——據說是十年前替商會搶運北荒凍木時被碎冰剮斷的。\n");
    set_id(({ "yunjin_wharf_master", "wharf_master", "boatman", "冰河船把頭", "船把頭", "把頭" }));

    setup_archetype("B", 16);
    set("class", "mortal");
    set("faction", "yunjin");
    set("roles", ({ "info" }));
    set("no_combat", 1);

    add_response(({ "貨船", "封凍", "冰河", "北境" }),
        "老把頭往凍僵的掌心呵了口白氣道：「每年霜降過後，冰河上游只剩半個月水路能放木排。天冷歸冷，只要貨棧沒斷工，咱們碼頭工一天還能掙上七十文貼補家用。」");
    add_response(({ "扛貨", "木料", "活計" }),
        "老把頭指著跳板盡頭成捆的紅杉木：「少壯後生若想活動筋骨掙點體力經驗，就去扛兩趟凍木料 (haul timber)，記住踩緊防滑麻繩別滑進冰窟裡！」");
}
