// clone/item/liefan_clay_batch.c
// 特級烈礬耐火泥出貨單 - 卷二第三幕核心物證

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("特級烈礬耐火泥出貨單", ({ "liefan clay batch", "liefan_clay_batch", "chuhuodan", "出貨單", "耐火泥單據" }));
    set_short(RED "【特級烈礬耐火泥出貨單】" NOR);
    set_long("一張自烈礬縣地火堡老爐頭韓老調處取得的原始出貨底單。\n"
             "紙張泛著暗紅色礬土粉塵，右下角赫然蓋著金石商會內堂專用的「金蓮環刀印」。\n"
             "單據上詳細載明三個月前商會內堂以特批密令提領三萬斤特級耐火白泥，指定運往金石府城工坊街私爐，\n"
             "與黑石鋪地煞私爐【丙字柒號】坩堝的高溫燒結物理成分完全吻合，為強間接佐證（corroborative）。\n");
    set_weight(50);
    set_value(500);
    set("is_evidence", 1);
    set("evidence_type", "liefan_clay");
    set("evidence_level", "corroborative");
}
