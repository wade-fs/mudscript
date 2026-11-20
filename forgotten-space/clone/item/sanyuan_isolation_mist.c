// /clone/item/sanyuan_isolation_mist.c
// 百草中和隔離霧劑暨沸血降燥湯（第三卷 Ch.119 半山毒域防護與長城輪替軍需）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("百草中和霧暨沸血降燥湯", ({ "sanyuan_isolation_mist", "isolation_mist", "百草中和霧", "沸血降燥湯" }));
    set_short(HIC "三元抗災組・百草隔離霧暨降燥湯" NOR);
    set_long("顧玄指揮二十口大鐵鍋熬配雪線苔乾粉、苦參、甘草與微溫礦灰調成的濕潤「百草中和隔離霧」，\n"
             "配生石灰線將結晶毒域壓止於距雲津盆地半里外（顧玄明註：此霧只遏擴散，殺不死鶴壽毒瘤）；\n"
             "並含供黑山長城二排破軍射手輪替服飲以緩氣血焚燥之【沸血降燥湯】配方單。\n");
    set_weight(320);
    set_value(0);
    set("is_consumable", 1);
}
