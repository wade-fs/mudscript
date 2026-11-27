// /clone/item/wanshan_charter_deed.c
// 《萬山共治分權章程暨多方交接總錄》（第三卷 Ch.123, Ch.125：拒為土皇帝、月讓四成利之人間錨點）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("萬山共治章程", ({ "wanshan_charter_deed", "wanshan_charter", "萬山共治分權章程", "交接總錄" }));
    set_short(HIY "萬山泥途總號・《萬山共治分權章程暨交接總錄》" NOR);
    set_long("沈泥在成為雲津實質第一大行商之夜拒絕太清特批與獨家定價權後，聯同顧蘭舟、羅九秤、\n"
             "邱禾、穆雪與八家中小商號代表共同簽印的分權契章與離境交接總錄：明定每月開放一次無預警\n"
             "查帳、拆分六條平行運輸標段、逾一萬靈石票需邱禾／顧蘭舟／八家代表三方會簽調度，並設\n"
             "全埠停票制裁條款。唯讓每一方都有對不公說不的底氣，九城總約根基方能真正長活。\n");
    set_weight(260);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "conclusive");
}
