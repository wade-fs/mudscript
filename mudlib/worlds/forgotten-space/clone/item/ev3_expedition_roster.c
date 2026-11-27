// /clone/item/ev3_expedition_roster.c
// 五年前走山隊名冊殘頁（第三卷 Ch.104 黑冰斷谷生牛皮箭筒夾層所得）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("五年前走山隊名冊殘頁", ({ "ev3_expedition_roster", "expedition_roster", "roster", "走山隊名冊殘頁", "名冊殘頁" }));
    set_short(WHT "五年前走山隊名冊殘頁（編號封存）" NOR);
    set_long("藏於生牛皮箭筒夾層中得以避開濕氣的兩頁殘缺名冊，記有天興十九年臘月走山隊隊員、\n"
             "金石商會聘用嚮導燕山、十名護衛腳夫及兩名接應斥候（含韓林）姓名與物資配額。\n"
             "缺頁嚴重，僅能作多方核驗後之旁證使用。\n");
    set_weight(100);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "corroborative");
}
