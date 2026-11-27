// /clone/item/bahuang_logistics_copy.c
// 天興十九年黑山軍需出庫副本（第三卷 Ch.94 雷烈交付）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("黑山軍需出庫副本", ({ "bahuang_logistics_copy", "logistics copy", "bahuang ledger", "黑山軍需出庫副本", "軍需副本" }));
    set_short(YEL "天興十九年・軍需出庫副本" NOR);
    set_long("以三層蠟紙小心護存的軍需糧秣出庫多留副聯。其中赫然記載天興十九年冬大雪封山之際，\n"
             "曾有「三十斤非制式烈性開山火藥」，未經前線將領核簽，卻由兩名掛著「千機百巧門工坊印記」\n"
             "的暗差調往鬼哭冰澗方向；正本撤離存根則已被人從兵曹庫抽毀。\n");
    set_weight(50);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "corroborative");
}
