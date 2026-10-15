// clone/item/broken_scroll.c
// 殘破引氣訣 - 破落道童的隨身殘卷

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("殘卷", ({ "broken scroll", "scroll", "canjuan", "殘卷" }));
    set_short("殘破引氣訣");
    set_long("半卷受潮發黃的道家吐納抄本，邊角已被鼠齧殘缺。\n"
             "上面以墨筆勾畫著幾副粗淺的靜坐調息行氣圖，字跡斑駁。\n");
    set_weight(200);
    set_value(10);
}
