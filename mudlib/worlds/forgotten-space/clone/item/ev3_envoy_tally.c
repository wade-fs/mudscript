// /clone/item/ev3_envoy_tally.c
// 千機堂副執印暗金令牌暨調遣密令底頁（第三卷 Ch.110 冰谷伏擊搜獲）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("副執印暗金令牌暨密令", ({ "ev3_envoy_tally", "envoy_tally", "tally", "副執印暗金令牌", "密令底頁" }));
    set_short(HIY "千機堂副執印暗金令牌暨密令（封存）" NOR);
    set_long("自冰谷伏擊現場斃命的私盟大執事腰間帶手套取下的天工閣千機堂副執印暗金令牌，\n"
             "連同兩張未燒毀的《近期人員調遣密令與交割簽領紀錄底頁》，以及一把刀鞘印有與黑石鋪\n"
             "炸礦雷管同源雙聯印記之軍械批號配刀拓錄。可證該執事受天工閣領用庫存在直接文書\n"
             "派遣執行滅口；惟大執事未留口供，赤煉本人親令與否仍需比對工坊原始領用簿方能定案。\n");
    set_weight(180);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "corroborative");
}
