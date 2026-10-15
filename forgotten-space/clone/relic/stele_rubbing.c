// clone/relic/stele_rubbing.c
// 殘缺星圖拓片 - 史前大清洗斷碑的拓本

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("拓片", ({ "stele rubbing", "rubbing", "tuopian", "拓片" }));
    set_short("殘缺星圖拓片");
    set_long("這是一張從南谷溪灘洗衣石板上拓印下來的古老星紋拓片。\n"
             "紙面上的墨跡勾勒出許多晦澀難解的同心圓與折線，\n"
             "其軌跡與當今天地運轉的星圖截然相反，似乎來自某個被遺忘的太古紀元。\n"
             "隱隱散發著一絲難以察覺的歷史氣息。\n");
    set_weight(100);
    set_value(50);
}
