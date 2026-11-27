// /clone/item/ark_pod_nine_manifest.c
// 九號離艦救生艙登錄總冊 (Ch.138 證實北荒方舟真相與無主材料裁定)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("九號艙登錄總冊", ({ "ark_pod_nine_manifest", "ark manifest", "manifest", "登錄總冊", "九號艙總冊" }));
    set_short(CYN "萬物登錄廳・九號離艦救生艙總冊" NOR);
    set_long("自萬物主機城登錄廳抄出的太古船塢檔案：確認北荒冰層方舟僅為『九號離艦救生艙』，\n"
             "亦明載未入舊離艦名冊之石堡遺民俱被主機判為『無主可回收材料』，另附戰祖冒領鹽晶轉帳單。\n");
    set_weight(80);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "corroborated");
}
