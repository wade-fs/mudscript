// /clone/item/brittle_shahuomou_shard.c
// 煞火魔偶暗紫脆化主軸殘屑（第三卷 Ch.113 東台器試火漆封存檢材）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("煞火魔偶脆化主軸殘屑", ({ "brittle_shahuomou_shard", "shahuomou_shard", "煞火魔偶殘屑", "脆化主軸" }));
    set_short(HIR "火漆封存・煞火魔偶暗紫脆化主軸樣本" NOR);
    set_long("魯長老與章百鍊在東側百工器試台自被三錘定軸停機的丈二「煞火魔偶」腹腔內刮出封樣：\n"
             "內含接觸異常暗紅晶柱後生出嚴重暗紫脆化麻點的玄鐵精鋼軸屑與半截發黑紅晶塊，\n"
             "與北荒方舟現場之鑽山傀儡脆化特徵與《萬機地窟領用簿》批次完全互相呼應。\n");
    set_weight(350);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "corroborative");
}
