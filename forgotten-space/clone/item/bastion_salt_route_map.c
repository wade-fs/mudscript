// /clone/item/bastion_salt_route_map.c
// 石堡舊鹽道羊皮圖 (Ch.132 戚老頭交付之機隼避檢盲點圖)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("石堡舊鹽道羊皮圖", ({ "bastion_salt_route_map", "salt route map", "route map", "羊皮圖", "舊鹽道圖" }));
    set_short(RED "暗紅羊皮・石堡舊鹽道盲點圖" NOR);
    set_long("一張邊角焦脆的暗紅獸皮地圖，上頭以炭粉標出灰燼石堡外圍三條避開巡檢機隼的\n"
             "地下舊鹽道、通往正東荒漠與正北白玉階座的折返點，以及西南焦土哨卡盲區。\n");
    set_weight(30);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "route_intel");
}
