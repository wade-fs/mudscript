// clone/npc/gong_gate_tiechigong.c
// 鐵尺公・行會知事 (gong_gate_tiechigong) - 百工總會外門

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("鐵尺公");
    set_short(CYN "百工總會知事" NOR " 鐵尺公");
    set_long("一位手持三尺精鋼量天尺、面容刻板嚴肅的老知事。\n"
             "他鎮守百工總會外門，專司百工學徒入門登記與材料資質初審，生平最恨偷工減料之輩。\n");
    set_id(({ "gong_gate_tiechigong", "tiechigong", "tie chi gong", "deacon tie", "鐵尺公", "行會知事", "知事" }));

    setup_archetype("A", 25);
    set("class", "gong_initiate");
    set("faction", "gong");
    set("roles", ({ "gatekeeper", "info", "quest_giver" }));
    set("schedule", "day");

    add_response(({ "登記", "學徒", "考核", "百工", "資質" }),
        "鐵尺公舉起手中精鋼鐵尺：「規矩方圓，分毫不差！欲入百工總會，須先通材料辨識與應力幾何。入內往萬機正堂拜見歐陽匠首，或去各分業工坊歷練！」");
}
