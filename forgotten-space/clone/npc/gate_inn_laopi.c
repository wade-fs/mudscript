// clone/npc/gate_inn_laopi.c
// 老皮・店小二 (gate_inn_laopi) - 北關外車馬店

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("老皮");
    set_short(YEL "關外車馬店小二" NOR " 老皮");
    set_long("一位披著羊皮坎肩、手腳麻利的車馬店伙計，長年伺候北來南往的塞外商旅。\n");
    set_id(({ "gate_inn_laopi", "laopi", "lao pi", "waiter pi", "老皮", "店小二" }));

    setup_archetype("J", 8);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "info", "service" }));
    set("schedule", "24h");

    add_response(({ "雪原", "荒原", "風向", "鎮風", "商旅" }),
        "老皮一邊往火盆裡添炭一邊說道：「從鎮風縣天風要塞下來的皮貨客說，今年北荒的裂石罡風比往年早了一個月，重弓和皮甲在北邊漲得厲害！」");
}
