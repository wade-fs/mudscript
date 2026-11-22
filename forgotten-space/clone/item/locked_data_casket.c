// /clone/item/locked_data_casket.c
// 鎖死讀數銅匣 (Ch.136 衡真道人託柳清虛交萬物匠師拆解之跨極物證)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("鎖死讀數銅匣", ({ "locked_data_casket", "data casket", "casket", "讀數銅匣", "銅匣" }));
    set_short(HIY "太虛校星院・鎖死讀數銅匣" NOR);
    set_long("一枚以偏心太古銅榫鎖死的巴掌大青銅小匣，裡頭封存著太虛三百年校準預熱增量\n"
             "與主機供能連動刻痕；須交由萬物外環高明匠師替換穩壓銅芯方能開匣。\n");
    set_weight(180);
    set_value(0);
    set("is_evidence", 1);
}
