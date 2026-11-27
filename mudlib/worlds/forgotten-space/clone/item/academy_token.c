// clone/item/academy_token.c
// 學塾白鹿青衿 - 金石都城合法身分緩衝信物 (路徑 A)

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("學塾白鹿青衿", ({ "academy token", "token", "qingjin", "青衿", "白鹿青衿" }));
    set_short(HIC "【學塾白鹿青衿】" NOR);
    set_long("金石學塾陸夫子簽發的文墨謄抄身份憑證。一件素色長布儒袍，\n"
             "領口繡著白鹿銜經圖紋。持此青衿，在都城享有十四天合法居留資格，自由出入文庫客棧，不受城防兵盤查。\n");
    set_weight(400);
    set_value(200);
    set("is_legal_buffer", 1);
    set("buffer_type", "academy");
}
