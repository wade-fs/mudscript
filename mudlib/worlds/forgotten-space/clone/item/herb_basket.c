// clone/item/herb_basket.c
// 竹編小藥簍 - 採藥孤兒的隨身採藥用具

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("藥簍", ({ "herb basket", "basket", "yaolou", "藥簍" }));
    set_short("竹編小藥簍");
    set_long("一個用青竹條細密編制的小簍子，散發著淡淡的泥土與草藥清香。\n"
             "可以用來盛放從山谷採掘下來的鮮活草葉根莖。\n");
    set_weight(400);
    set_value(15);
}
