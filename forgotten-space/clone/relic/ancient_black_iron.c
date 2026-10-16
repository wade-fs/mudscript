// clone/relic/ancient_black_iron.c
// 太古不融黑鐵構件 - 史前工聖失落的微型齒輪與機關榫卯

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("黑鐵構件", ({ "black iron", "ancient iron", "gear", "iron", "不融黑鐵", "黑鐵構件", "太古黑鐵", "至高神械殘片" }));
    set_short(HIB "太古不融黑鐵構件" NOR);
    set_long("一截只有拇指大小、通體烏黑啞光的太古至高神械構件。\n"
             "這塊神物曾被萬年焦黑石皮死死包裹，因太小太畸形被老鐵匠嫌棄踢進廢料堆墊底；\n"
             "直到常規粗礦用盡、少年福至心靈如賭石行家般一錘砸裂厚重石皮，方使神物重見天日。\n"
             "入手極沉且散發著徹骨寒意，投入萬度烈火地爐中也絲毫不融。\n"
             "表面雕刻著數圈細如游絲的微型齒輪與榫卯卡榫，隱隱透出太古大清洗前失落的「物宗・至高工聖神械」之理。\n");
    set_weight(250);
    set_value(500);
    set("is_relic", 1);
    set("relic_type", "wu_gear");
}
