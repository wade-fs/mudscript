// clone/item/tainted_pelt.c
// 染煞異獸皮 - 沾染了大荒地煞深處紫黑濁血的狂暴凶獸皮

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("獸皮", ({ "tainted pelt", "pelt", "skin", "shoupi", "獸皮", "異獸皮" }));
    set_short(MAG "染煞異獸皮" NOR);
    set_long("一張自狂暴凶獸身上剝下的殘破厚皮，皮毛散發著濃烈的硫磺焦味與暗紫色濁血痕跡，\n"
             "隱隱透出大荒深處地煞動盪的凶煞氣息。\n");
    set_weight(1200);
    set_value(60);
    set("is_pelt", 1);
}
