// /clone/item/ev3_yanshan_blood_note.c
// 燕山半片舊羊皮血書（第三卷 Ch.104 黑冰斷谷岩石凹槽封樣）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("燕山羊皮血書殘片", ({ "ev3_yanshan_blood_note", "yanshan_blood_note", "blood note", "燕山羊皮血書殘片", "血書" }));
    set_short(RED "燕山羊皮血書殘片（雙重封存）" NOR);
    set_long("自黑冰斷谷岩石凹槽內以竹夾溫烤剝離、置於雙層封存木匣中的半片脆化羊皮。\n"
             "通篇以指血急促寫就，末角尚存模糊「山」字落款，正文殘文可辨：\n"
             "『天興十九年臘月……行至黑冰深處……忽遇暗……內堂調來之開山重藥非為開路……炸……接應未至……雷……非……』\n"
             "後半截遭冰裂腐毀、無人名與公章，需與雷烈軍需副聯交叉核驗（目前不得單獨指認個人）。\n");
    set_weight(90);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "corroborative");
}
