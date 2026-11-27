// /clone/item/taixu_calibration_log_copy.c
// 太虛三百年老化校準抄本 (Ch.136 證實白玉晶核制度)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("太虛校準抄本", ({ "taixu_calibration_log_copy", "calibration log", "抄本", "太虛校準抄本" }));
    set_short(HIW "校星院・三百年老化校準抄本" NOR);
    set_long("衡真道人私下抄錄的太虛偏殿維護實錄，逐筆載明每三百年校準脈衝衰減半拍、\n"
             "必須以新進極境修士凝成『玉化晶核』替補陣眼方能勉強維持運轉之殘酷真相。\n");
    set_weight(60);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "corroborated");
}
