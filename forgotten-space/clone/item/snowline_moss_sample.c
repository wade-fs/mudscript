// /clone/item/snowline_moss_sample.c
// 雪線苔樣本（第三卷 Ch.89 百毒試藥谷・中和寒髓草地煞之共生微苔）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("雪線苔樣本", ({ "snowline_moss_sample", "snowline moss", "moss sample", "雪線苔樣本", "雪線苔" }));
    set_short(HIC "雪線苔與水垢密封管" NOR);
    set_long("一截封於雙層瓷管內的冰藍色細微苔蘚，附帶著少許來自百草谷寒髓草根鬚邊緣的\n"
             "酸澀礦泥樣本。經顧玄冷萃實測，此苔能顯著吸附並中和靈草脈絡中混入的地煞濁氣。\n");
    set_weight(60);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "lead_only");
}
