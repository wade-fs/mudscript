// clone/item/ore_chunk.c
// 北崖粗鐵礦核 - 從黑石斷崖古礦道開採出的重型原礦

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("粗鐵礦", ({ "ore chunk", "ore", "iron ore", "礦石", "粗礦", "礦核", "粗鐵礦" }));
    set_short(CYN "北崖粗鐵礦核" NOR);
    set_long("一塊從北崖深處開採下來的暗青色橢圓重礦石，外層包裹著厚厚的岩石外殼，\n"
             "隱約透出沉凝的金屬反光。可拿到老鐵匠鋪的鐵砧上用鐵錘敲擊鍛打 (strike ore)。\n");
    set_weight(3000);
    set_value(25);
    set("is_ore", 1);
}
