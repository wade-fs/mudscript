// clone/npc/gate_plaza_deputy.c
// 雷震・巡防副將 (gate_plaza_deputy) - 北關前校場

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("雷震");
    set_short(HIR "北關巡防副將" NOR " 雷震");
    set_long("一位身披魚鱗鐵甲、按劍立於北關前校場將台上的邊軍副將。\n"
             "他率領邊軍先鋒營駐紮於此，常年發布協防官道與押送軍械物證的軍務委託。\n");
    set_id(({ "gate_plaza_deputy", "lei zhen", "leizhen", "deputy general", "雷震", "巡防副將", "副將" }));

    setup_archetype("C", 30);
    set("class", "wu_initiate");
    set("faction", "wu");
    set("roles", ({ "guard", "quest_giver", "info" }));
    set("schedule", "day");

    add_response(({ "協防", "押送", "軍令", "北關", "物證" }),
        "雷震按劍肅然道：「北山煞潮將起，黑石關與鎮風縣軍報頻傳！凡具力道根底或武館腰牌之義士，皆可在本將處接取官道協防與物證押送軍務！」");
}
