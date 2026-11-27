// clone/npc/folk/qian_trapper.c
// 老套手錢七・山麓烘肉寮（山林燻肉存冬與捕獸夾日常生計） (Ch.58-67)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("老套手錢七");
    set_short(YEL "山麓獵戶" NOR " 錢七");
    set_long("一位左耳缺了半片、滿手老繭與松煙黑灰的乾瘦老獵人。\n"
             "他不像趙老獵那樣盯著大荒深處的異獸，一輩子只在山腳下套野兔山雞、用柏枝燻臘肉幫村裡人備過冬口糧。\n");
    set_id(({ "qian_trapper", "qian", "trapper", "老套手錢七", "錢七", "老獵戶" }));

    setup_archetype("D", 9);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "hunter", "info" }));
    set("no_combat", 1);

    add_response(({ "燻肉", "臘肉", "過冬", "生計" }),
        "錢七往燻坑裡丟了把濕柏葉笑道：「山裡冬長，鮮肉放不過兩日就臭！抹上粗鹽再用青岡木與柏葉慢慢陰火燻透，掛在樑上撐到明年開春都不壞。你要手癢就照著燻架學著翻翻肉（cure meat）。」");
    add_response(({ "獸夾", "下套", "野豬", "大荒" }),
        "錢七搓了搓生鏽的鐵夾嘆道：「前陣子東林裡野物脾氣越來越暴，連我們下在山腳的鐵套子都被野豬連根拔斷過兩回……少往深林去，夠吃一口就收手。」");
}
