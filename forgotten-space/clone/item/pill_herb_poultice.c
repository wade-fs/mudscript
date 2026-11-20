// /clone/item/pill_herb_poultice.c
// 雪線續脈膏與沸血雄黃煙袋（第三卷 Ch.103 永凍血原半寸對照實驗與戰術煙彈）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("雪線續脈膏暨雄黃煙袋", ({ "pill_herb_poultice", "herb_poultice", "smoke_pouch", "雪線續脈膏", "沸血雄黃煙" }));
    set_short(HIG "雪線續脈膏暨沸血雄黃煙實測組" NOR);
    set_long("粗陶藥碗盛裝的雪線苔配生薑末「雪線續脈膏」，旁附三枚特製皮革【沸血雄黃煙】。\n"
             "附有白岩與顧玄共同簽名歸檔的半寸對照病理標籤：塗敷左腳腕一晚上即消腫七成、完勝\n"
             "白岩原方凍傷膏；同時標明禁忌條款——「極寒低壓環境下，雄黃艾草煙霧倒灌側風口\n"
             "會劇烈刺激人類肺部氣管」。\n");
    set_weight(280);
    set_value(50);
    set("is_consumable", 1);
}
