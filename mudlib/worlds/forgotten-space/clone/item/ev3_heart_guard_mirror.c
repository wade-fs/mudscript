// /clone/item/ev3_heart_guard_mirror.c
// 燕山隨身精銅護心鏡（第三卷 Ch.105 荒古戰神遺塚裂隙邊緣）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("燕山精銅護心鏡", ({ "ev3_heart_guard_mirror", "heart_guard_mirror", "mirror", "燕山精銅護心鏡", "護心鏡" }));
    set_short(HIY "燕山精銅護心鏡（凹損遺物）" NOR);
    set_long("於荒古戰神遺塚最右側一丈寬暖風裂隙入口的青黑石板邊緣、五尺凍血跡盡頭石縫裡\n"
             "拾獲的舊精銅圓鏡。鏡面邊緣被長期磨得鋥亮，中央卻生生被巨力砸凹半邊（足以震碎\n"
             "尋常武夫臟腑）；背面被人以刀尖粗獷鑿刻了一個歪斜的「燕」字。此鏡僅能證明燕山當年\n"
             "重傷爬抵裂隙邊緣，裂隙內未見遺骸亦無生火或字跡，其生還與否仍屬未決懸案。\n");
    set_weight(420);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "lead_only");
}
