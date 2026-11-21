// /clone/item/reverse_star_addendum.c
// 《逆星歲差實測補遺（附反例開放聲明）》（第三卷 Ch.122：以可推翻實證破妄入 Lv.100）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("逆星歲差補遺", ({ "reverse_star_addendum", "star_addendum", "逆星歲差實測補遺", "逆星歲差補遺" }));
    set_short(HIW "周天星律院・《逆星歲差實測補遺》" NOR);
    set_long("柳清虛匯總上千組冬春實測寫成之公開模型修訂錄，首頁以炭筆親題：「本模型僅限於近\n"
             "三百年北境高寒帶星力基準誤差校正，隨時歡迎以未來實測反例推翻改寫」。文末保留\n"
             "沈照塵現場比對出的兩組氣流反例，並註明每三百年校準一次之二十八宿天羅法陣尚待\n"
             "查明幕後驅動者與假天覆蓋疆域。\n");
    set_weight(190);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "conclusive");
}
