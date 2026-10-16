// clone/item/timber.c
// 加固硬木料 - 砍伐東林硬木製成的礦道加固坑木

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("硬木料", ({ "timber", "wood", "坑木", "加固木料", "木料", "硬木料" }));
    set_short(YEL "加固硬木料" NOR);
    set_long("一根自東林深處採伐的陳年鐵硬老木，質地沉重如生鐵。\n"
             "可用於北崖古礦道支撐加固 (可交付給北崖老礦工魯大山)。\n");
    set_weight(250);
    set_value(20);
    set("is_timber", 1);
}
