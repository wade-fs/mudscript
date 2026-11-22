// /clone/npc/zhanzu_quartermaster_han.c
// 韓石（戰祖魔殿・西南外獵監軍，中階具名反派）(Ch.139-140, 150-151, 156, 159)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("韓石");
    set_short(HIR "西南外獵監軍" NOR " 韓石");
    set_long("一名身材魁梧、腰纏重鐵軍需算牌的戰祖魔殿西南監軍，雙眼總帶著壓榨奴役的冷狠。\n"
             "他靠虛報狩獵耗損與冒領萬物鹽晶粉積累軍功，一旦假帳曝光便會不擇手段滅口封營。\n");
    set_id(({ "zhanzu_quartermaster_han", "quartermaster han", "han shi", "韓石", "監軍" }));

    setup_archetype("C", 93);
    set("class", "wu");
    set("path", "li");
    set("faction", "zhanzu_command");
    set("roles", ({ "antagonist", "quest" }));
    set("no_auto_attack", 1);
    set("home_room", "/d/realm/zhanzu/hunting_camp.c");

    add_response(({ "配額", "獸髓", "鬥獸坑" }),
        "韓石冷笑拍著腰間鐵牌：「九具三階心核少一顆，你們整隊就全進演武坑替老子餵獸！\n"
        "至於那個總愛多嘴的老獨眼龍，早晚要查他個通敵之罪。」");
}
