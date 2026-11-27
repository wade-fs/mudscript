// clone/item/rubbing_kit.c
// 粗黃草紙與炭黑條 - 拓印石碑與抄錄道藏符文的必備工具

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("拓印工具", ({ "rubbing kit", "kit", "paper", "charcoal", "草紙", "炭黑", "拓印工具" }));
    set_short(YEL "粗黃草紙與炭黑條" NOR);
    set_long("一疊用來包藥草與抄錄偏方的粗黃草紙，以及一截半乾的柳木炭黑條。\n"
             "常年被採藥人與道觀學徒用來隨身記錄石刻拓本與藥理。\n"
             "（在古蹟遺跡處使用 tuoyin 指令時將消耗此工具）\n");
    set_weight(100);
    set_value(20);
    set("is_rubbing_kit", 1);
}
