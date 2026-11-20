// /clone/item/sample_discarded_pill.c
// 廢丹紫泥硬渣暨試藥白猿樣本匣（第三卷 Ch.97 廢丹崖）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("廢丹紫泥樣本匣", ({ "sample_discarded_pill", "discarded pill", "pill sample", "廢丹紫泥樣本匣", "廢丹樣本" }));
    set_short(MAG "雙層封存木匣（紫泥硬渣）" NOR);
    set_long("顧玄帶甘草口罩與厚鹿皮手套自廢丹崖深溝採集的雙層封存木匣，封條上留有回收工頭陶生的\n"
             "指紋見證。匣內分格封裝著三塊泛著暗紅硫磺油脂光澤的「紫泥封口硬渣」，並附有一份五頁病理解剖\n"
             "筆記與十七份匿名丹鼎病案統計（「甲一、乙三」）：前三月假性壓抑道化，第四月起不可逆血煞癌變。\n");
    set_weight(140);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "corroborative");
}
