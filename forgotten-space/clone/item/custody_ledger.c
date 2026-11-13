// clone/item/custody_ledger.c
// 押解移交文卷 - 黑石關至金石府城人犯移交公文

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("押解移交文卷", ({ "custody ledger", "ledger", "wenjuan", "文卷", "押解文卷", "押解移交文卷" }));
    set_short(HIY "【押解移交文卷】" NOR);
    set_long("一份以牛皮紙封套嚴密封緘的官辦押解文卷，蓋有黑石關巡檢司大印與沿途驛站連署印信。\n"
             "詳細載錄了要犯趙德貴涉嫌毒害商隊、私運精礦與勾結外寇之案由，需呈交府衙案牘庫主簿核驗簽押。\n");
    set_weight(80);
    set_value(100);
    set("is_custody_ledger", 1);
}
