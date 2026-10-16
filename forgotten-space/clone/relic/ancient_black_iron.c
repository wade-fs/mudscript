// clone/relic/ancient_black_iron.c
// 太古不融黑鐵構件 - 史前工聖失落的微型齒輪與機關榫卯

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("黑鐵構件", ({ "black iron", "ancient iron", "gear", "iron", "不融黑鐵", "黑鐵構件", "太古黑鐵" }));
    set_short(HIB "太古不融黑鐵構件" NOR);
    set_long("一截只有拇指大小、通體烏黑啞光的神秘金屬構件。入手極沉且散發著徹骨寒意，\n"
             "即使投入萬度烈火地爐中也絲毫不融。表面雕刻著數圈細如游絲的微型齒輪與榫卯卡榫，\n"
             "隱隱透出太古大清洗前失落的「物宗・工聖機關造物」之理。\n");
    set_weight(250);
    set_value(500);
    set("is_relic", 1);
    set("relic_type", "wu_gear");
}
