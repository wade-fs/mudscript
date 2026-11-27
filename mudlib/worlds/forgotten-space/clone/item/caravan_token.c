// clone/item/caravan_token.c
// 車馬行短褐腰牌 - 金石都城合法身分緩衝信物 (路徑 B)

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("車馬行短褐腰牌", ({ "caravan token", "token", "badge", "腰牌", "短褐腰牌" }));
    set_short(YEL "【車馬行短褐腰牌】" NOR);
    set_long("遠行車馬大院鏢頭簽發的重車搬運苦力牌子。正面烙印著車馬軲轆印記，\n"
             "持此腰牌享有七天合法居留資格，可承接城內外大木大石腳力與押車差役。\n");
    set_weight(200);
    set_value(50);
    set("is_legal_buffer", 1);
    set("buffer_type", "caravan");
}
