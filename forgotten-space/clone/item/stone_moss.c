// clone/item/stone_moss.c
// 生石膽苔 - 採集自南谷墜龍瀑布絕壁背面的劇毒藥石材料 (小說第8章)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("生石膽苔", ({ "stone moss", "moss", "生石膽苔", "石膽苔" }));
    set_short(HIG "生石膽苔" NOR);
    set_long("一把泛著暗青色油潤微光的濕潤苔蘚。生長於南谷墜龍瀑布陰冷潮濕的石壁背面，\n"
             "藥性極陰極烈，帶有一股刺鼻的微苦藥氣。配透骨草可活血化瘀，但若遇生石灰與熱水，\n"
             "則會化作灼眼腐骨的致命毒霧。\n");
    set_weight(50);
    set_value(120);
    set("material", "herb");
    set("poison_level", 2);
}
