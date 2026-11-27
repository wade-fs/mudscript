// /clone/item/ninety_city_treaty_copy.c
// 九城古商盟總契金屬拓錄暨雲記殘頁抄本（第三卷 Ch.108 後勤控室合璧所得）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("九城總契拓錄暨舊盟抄頁", ({ "ninety_city_treaty_copy", "treaty_copy", "九城總契拓錄", "雲記殘頁抄本" }));
    set_short(HIY "《九城總契・禁毀條例第七條》拓本" NOR);
    set_long("柳清虛於方舟後勤石鋼廳室逐字臨摹的耐腐蝕金屬捲軸副本，夾帶發現於控制台旁的\n"
             "兩頁關鍵泛黃皮紙（一頁邊角印「雲記」暗章並記「乙巳年舊盟未結轉帳：玄木」；\n"
             "另一頁記載『……乙字批母液採辦金流……經金石商會內堂副席轉撥……對接「丹鼎丙柒」、\n"
             "「天工赤火」、「太清雷律」三處專責執事』）。條例明定九城總調度使負「九州避難火種」\n"
             "之責並嚴禁交出北境地脈安全閥開採圖紙——揭示三十年前舊商盟清洗及沈雲妮身世第五階段核心。\n");
    set_weight(150);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "corroborative");
}
