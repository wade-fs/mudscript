// clone/item/clinic_token.c
// 杏林藥囊腰牌 - 金石都城合法身分緩衝信物 (路徑 C)

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("杏林藥囊腰牌", ({ "clinic token", "token", "yaonang", "藥囊", "杏林藥囊腰牌" }));
    set_short(HIG "【杏林藥囊腰牌】" NOR);
    set_long("杏林醫館館主白先生頒發的試藥藥童布牌。內附三味驅蟲防瘴乾草，\n"
             "散發淡淡藥香。持此腰牌享有十天合法居留資格，自由出入藥圃與市集收購靈草。\n");
    set_weight(150);
    set_value(100);
    set("is_legal_buffer", 1);
    set("buffer_type", "clinic");
}
