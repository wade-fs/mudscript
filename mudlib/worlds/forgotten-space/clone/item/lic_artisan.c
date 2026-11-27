// clone/item/lic_artisan.c
// 百工初階匠帖 - 金石府百工總會職業憑證

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("百工初階匠帖", ({ "artisan license", "lic_artisan", "jiangtie", "匠帖", "百工匠帖" }));
    set_short(HIY "【百工初階匠帖】" NOR);
    set_long("由百工總會匠首歐陽大師與莫錘大師聯名核發的初階匠師執照。\n"
             "牌面以硬木嵌銅絲鑲邊，烙有千錘規矩印。持牌者在府城享有合法工籍居留資格，\n"
             "可承攬各類器械維修、鍛造與營造工程，並享有百工總堂工料七折優惠。\n");
    set_weight(150);
    set_value(300);
    set("is_legal_buffer", 1);
    set("license_career", "gong");
}
