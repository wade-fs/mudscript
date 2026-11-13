// clone/item/lic_escort_guard.c
// 八方鏢師總帖 - 金石府城八方武館與鏢局憑證

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("八方鏢師總帖", ({ "escort guard license", "lic_escort_guard", "biaoshitie", "鏢師帖", "八方鏢師帖" }));
    set_short(HIR "【八方鏢師總帖】" NOR);
    set_long("由八方武館總教頭霸山親手鐫刻的黑鐵鏢師令牌。\n"
             "牌面雕有踏浪重岩圖案，象徵身如磐石、無懼凶險。持此總帖者享有府城合法武裝通行資格，\n"
             "可自由攜帶重械過關，並具備承接府城往返六縣重載鏢車押運護送的法定資質。\n");
    set_weight(200);
    set_value(300);
    set("is_legal_buffer", 1);
    set("license_career", "wu");
}
