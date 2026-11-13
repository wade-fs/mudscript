// clone/item/fengshi_quartz.c
// 天風谷極品風蝕石英核 - 卷二第三幕法修核心奇材

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("天風谷風蝕石英核", ({ "fengshi quartz", "fengshi_quartz", "quartz", "石英核", "風蝕石英" }));
    set_short(HIW "【天風谷風蝕石英核】" NOR);
    set_long("自鎮風縣天風谷萬仞絕壁鷹嘴崖巔採集而來的極品風蝕石英核。\n"
             "在億萬年如刀罡風與極寒冰霜的淬鍊下，晶體通透如無物，不含一絲雜質氣泡。\n"
             "柳清虛以水銀渾天鏡精算三息風眼窗口、燕隼以神臂弓磐石錨索方才涉險採得。\n"
             "可用於打磨頂級渾天觀象鏡片以減少天體觀測誤差，恪守法修「精密器具輔助觀測而非天道領悟」之本分。\n");
    set_weight(80);
    set_value(1500);
    set("is_rare_material", 1);
    set("material_type", "quartz");
}
