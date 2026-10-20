// clone/npc/wu_gate_squadleader.c
// 陳鐵甲・值役隊正 (wu_gate_squadleader) - 鎮武軍鎮轅門

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("陳鐵甲");
    set_short(HIR "軍鎮值役隊正" NOR " 陳鐵甲");
    set_long("一位身披玄鐵重甲、按刀守在鎮武軍鎮鹿砦轅門前的值役隊正，雙目如炬。\n");
    set_id(({ "wu_gate_squadleader", "wu_gate_vanguard", "chen tiejia", "squadleader", "陳鐵甲", "值役隊正", "隊正" }));

    setup_archetype("B", 20);
    set("class", "wu_initiate");
    set("faction", "wu");
    set("roles", ({ "gatekeeper", "guard", "info" }));
    set("schedule", "24h");

    add_response(({ "募兵", "考核", "軍鎮", "八方武館", "力道" }),
        "陳鐵甲拍著胸前鐵甲朗聲道：「鎮武軍鎮與八方武館同氣連枝！此處不受酸腐道官的『絕靈法網』管轄，崇尚純陽氣血！想考取力道黑鐵腰牌者，入內往大校場舉石鎖！」");
}
