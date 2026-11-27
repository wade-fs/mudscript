// /clone/item/ev3_private_purchase_ledger.c
// 北境三宗延命私盟密帳索引（第三卷 Ch.98 雲海鬼市暗巷截獲）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("延命私盟密帳索引", ({ "ev3_private_purchase_ledger", "private purchase ledger", "secret ledger", "延命私盟密帳索引", "私盟密帳" }));
    set_short(RED "北境三宗延命私盟密帳索引" NOR);
    set_long("一本包著防火油布、自無標記灰袍經生馬背跌落的深灰薄冊。冊中詳列南方十三座府城貨源，\n"
             "第七欄正是被扳倒的「金石府・錢百川・金蓮記」，其下尚有六個未暴露白手套商號；每年上繳之\n"
             "無瑕靈石與特殊物資則記於「紫竹」、「赤火」、「玄爐」三組代號之下。末頁更現「乙巳年舊盟\n"
             "未結轉帳代號：玄木」之褪色舊錄。\n");
    set_weight(80);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "corroborative");
}
