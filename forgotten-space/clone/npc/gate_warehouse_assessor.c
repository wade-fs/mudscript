// clone/npc/gate_warehouse_assessor.c
// 金算盤・商會驗貨掌櫃 (gate_warehouse_assessor) - 官道大貨棧

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("金算盤");
    set_short(HIY "商會驗貨掌櫃" NOR " 金算盤");
    set_long("一位身穿褐色綢衫、手指戴著純金算盤戒的商會掌櫃。\n"
             "他代表金石商會駐守北關官道大貨棧，與官府書吏共同查驗大宗過境貨物與扣押走私密箱。\n");
    set_id(({ "gate_warehouse_assessor", "jin suanpan", "assessor jin", "金算盤", "驗貨掌櫃" }));

    setup_archetype("H", 18);
    set("class", "mortal");
    set("faction", "shanghui");
    set("roles", ({ "broker", "info", "quest_target" }));
    set("schedule", "day");

    add_response(({ "貨棧", "扣押", "貨箱", "走私", "坩堝" }),
        "金算盤壓低聲音道：「角落裡那批貼著封條的黑鐵貨箱，是上個月從南嶺黑石關截獲的無主查扣物……聽說裡頭還有工部官窯流出的紫銅除渣坩堝呢！」");
}
