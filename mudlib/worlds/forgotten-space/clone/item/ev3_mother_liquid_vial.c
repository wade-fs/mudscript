// /clone/item/ev3_mother_liquid_vial.c
// 北荒方舟冷卻母脈・血精母液封裝玉瓶（第三卷 Ch.106, Ch.109）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("血精母液封裝玉瓶", ({ "ev3_mother_liquid_vial", "mother_liquid_vial", "liquid_vial", "血精母液封裝玉瓶", "血精母液" }));
    set_short(MAG "血精母液封裝玉瓶（雙層冷封）" NOR);
    set_long("一只尚裝著半瓶濃稠暗血紫色高能液體、由特殊防漏封蠟徹底閉死的白玉接液瓶。\n"
             "經顧玄以一滴雪線苔提取液對照驗證，其內含太古方舟主引擎冷卻用「高能生物質凝膠與\n"
             "冷卻水銀結晶」，混雜地底硫磺濁氣後正與丹鼎宗丙柒廢丹渣及黑石古礦血毒同源——\n"
             "抽乾此液即相當於拆除北境地脈安全閥，恐釀半壁凍土陸沉之災。\n");
    set_weight(220);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "corroborative");
}
