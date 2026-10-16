// d/village/hunter_cabin.c
// 黑石鋪・林邊茅屋・獵戶哨亭 (獵戶之子出生地)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("林邊茅屋・獵戶哨亭");
    set_long("這是一座依著大荒鹿角柵欄搭建的高腳圓木哨亭。粗木牆上散發著松脂與煙燻\n"
             "氣息，樑上懸掛著幾條風乾肉條、幾張抹了防蟲油的灰狼皮與一副粗重獸弓。\n"
             "角落的火塘 (hearth) 裡燃著苦艾草與枯松枝，青煙裊裊 (smoke)。推開厚木門，\n"
             "眼前便是遮天蔽日的大荒外緣，遠處不時傳來狼嚎禽鳴。\n");

    set_exits(([
        "south":     "/d/village/forest.c",
        "west":      "/d/village/square.c",
        "northwest": "/d/village/square.c",
    ]));

    set("is_outdoor", 0);

    spawn_npc("/clone/npc/zhao_hunter.c");
    spawn_item("/clone/weapon/heavy_bow.c");
    spawn_item("/clone/weapon/bamboo_arrow.c");
}

void init() {
    ::init();
    add_action("do_smoke", "smoke");
    add_action("do_smoke", "點艾草");
    add_action("do_smoke", "燒艾");
}

int do_smoke(string arg) {
    object me = this_player();
    write("你往火塘裡添了兩捧苦艾乾草與枯松枝，抓起吹火筒輕輕一吹...\n");
    write(HIG "辛香微苦的艾草青煙升騰而起，驅散了窗外嗡嗡作響的荒山毒虻，整間哨亭一片寧靜清幽。\n" NOR);
    write(YEL "【艾草青煙滌蕩心脾，你的神識清醒，疲憊感消退了（氣血 +15、神識 +25、精力 +25）。】\n" NOR);

    me->add(VITAL_KEE, 15);
    me->add(VITAL_SEN, 25);
    me->add(VITAL_SP, 25);
    return 1;
}
