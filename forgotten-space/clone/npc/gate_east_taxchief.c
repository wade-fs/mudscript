// clone/npc/gate_east_taxchief.c
// 褚嚴・東關督稅官 (gate_east_taxchief) - 金石東關城門

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("褚嚴");
    set_short(HIR "東關督稅官" NOR " 褚嚴");
    set_long("一位面色鐵青、腰懸銅製驗礦牌的府城稅官，身旁跟著巡檢司武卒。\n"
             "他專司查驗烈礬縣與濁水縣運入的硫礬、赤銅與黑市礦料，嚴防高濃度地煞血精混入都城。\n");
    set_id(({ "gate_east_taxchief", "chu yan", "chuyan", "taxchief", "褚嚴", "東關督稅官", "督稅官" }));

    setup_archetype("A", 22);
    set("class", "mortal");
    set("faction", "yamen");
    set("roles", ({ "gatekeeper", "tax", "info" }));
    set("rules", ([ "fire_hazard_tax_pct": 5, "raw_copper_reserve_pct": 10, "contraband": "blood_sha_ingot" ]));
    set("schedule", "day");

    add_response(({ "地火危險稅", "硫礬", "赤銅", "血精", "東關" }),
        "褚嚴冷聲道：「凡自烈礬、濁水入東關之硫礬、赤銅，一率加徵半成『地火危險稅』，生銅另扣一成充入官鑄留底！若敢夾帶未經除渣的高濃度地煞血精晶錠，當場格殺勿論！」");
}
