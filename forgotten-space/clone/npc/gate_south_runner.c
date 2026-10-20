// clone/npc/gate_south_runner.c
// 刁小七・流民牙子 (gate_south_runner) - 南關車馬小棧

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("刁小七");
    set_short(YEL "流民牙子" NOR " 刁小七");
    set_long("一位身材瘦小、眼神機靈活絡的市井牙人，常年在南關車馬小棧招攬初入城的流民介紹短工。\n");
    set_id(({ "gate_south_runner", "diao xiaoqi", "xiaoqi", "runner", "刁小七", "流民牙子", "牙子" }));

    setup_archetype("I", 8);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "broker", "info" }));
    set("schedule", "day");

    add_response(({ "雜工", "門路", "短工", "活計" }),
        "刁小七湊過來笑道：「剛從南嶺山裡出來的吧？力氣大的去南關外初堆棧找石大柱搬木石，識字懂禮的去學塾找陸夫子，懂藥草的去杏林醫館找白先生！」");
}
