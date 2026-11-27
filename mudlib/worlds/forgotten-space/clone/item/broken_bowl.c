// clone/item/broken_bowl.c
// 豁口破陶碗 - 街巷市井流浪刨食的粗鄙家當

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("破陶碗", ({ "broken bowl", "bowl", "pottery bowl", "破碗", "陶碗", "破陶碗" }));
    set_short(WHT "豁口破陶碗" NOR);
    set_long("一隻豁了三個大口的灰黑粗陶破碗，表面油漬斑駁、沾著洗不淨的煤黑與泥漬。\n"
             "在黑石鋪的陰暗後巷與客棧屋簷下，這是流浪乞兒遮掩耳目、討要殘羹冷飯的唯一立足家當。\n");
    set_weight(200);
    set_value(5);
    set("is_bowl", 1);
}
