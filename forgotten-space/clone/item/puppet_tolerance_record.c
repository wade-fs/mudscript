// /clone/item/puppet_tolerance_record.c
// 搬山傀儡軸套公差工單（第三卷 Ch.88 千鍛地火廊・可複製應力修正紀錄）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("傀儡軸套公差工單", ({ "puppet_tolerance_record", "tolerance record", "gongdan", "傀儡軸套公差工單", "應力工單" }));
    set_short(YEL "青銅搬山傀儡・應力公差工單" NOR);
    set_long("一張沾著煤灰與機油味道的粗麻紙工單，上頭以工整炭筆詳記著「右肘第三軸套偏角\n"
             "半厘、內壁見不明暗紫焦黑脆化麻點（深 0.2 厘）」，並附有雙契榫楔退火與溫油慢淬曲線圖。\n");
    set_weight(40);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "lead_only");
}
