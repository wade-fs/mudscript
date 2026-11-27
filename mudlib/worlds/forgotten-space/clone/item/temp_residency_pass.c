// clone/item/temp_residency_pass.c
// 《金石南關暫住牌》- 底層流民於外城擔保登錄後取得之臨時居留牌證

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("金石南關暫住牌");
    set_short(YEL "《金石南關暫住牌》" NOR);
    set_long("一塊刻著編號與南關巡檢火漆押印的薄槐木腰牌，證明持有人已在外城登記去向，\n"
             "可免於夜間當街被城防軍作無籍野民鎖拿，並可在外城碼頭與車馬院按日領籌做工，\n"
             "但仍無資格進入內城大坊正式受僱或於中心客棧立約長住。\n");
    set_id(({ "temp_residency_pass", "temp residency pass", "temporary pass", "暫住牌", "腰牌" }));
    set("is_temp_pass", 1);
    set("value", 15);
    set("weight", 1);
}
