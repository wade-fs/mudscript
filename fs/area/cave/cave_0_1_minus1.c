// mudlib/area/cave/cave_0_1_minus1.c - 洞穴內部
#include <globals.h>
inherit ROOM;

void create() {
    
    set("short", select_lang(([
        "en": "Deep Cave",
        "zh-TW": "洞穴深處",
        "zh-CN": "洞穴深处"
    ])));
    set("long", select_lang(([
        "en": "The cave gets darker. Many bats are hanging on the ceiling.
",
        "zh-TW": "洞穴越來越深，天花板上掛著許多蝙蝠。
",
        "zh-CN": "洞穴越来越深，天花板上挂着许多蝙蝠。
"
    ])));
    set("coordinate", ({ 0, 1, -1 }));
    set_is_outdoor(0);
    set("exits/" + "south", "./cave_0_0_minus1.c");
}

void reset() {
    ::reset();
    spawn_npc("/npc/creature/bat.c");
}
