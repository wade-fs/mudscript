// clone/npc/south_warehouse_grain_scale.c
// 方平斗・斗秤官 (south_warehouse_grain_scale) - 官商聯營大糧倉

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("方平斗");
    set_short(CYN "大糧倉斗秤官" NOR " 方平斗");
    set_long("一位手持官製銅斛量斗與插糧探筒的嚴謹書吏，負責查驗入庫漕糧的成色與乾濕度。\n");
    set_id(({ "south_warehouse_grain_scale", "fang pingdou", "scale officer", "方平斗", "斗秤官" }));

    setup_archetype("A", 12);
    set("class", "mortal");
    set("faction", "yamen");
    set("roles", ({ "service", "info" }));
    set("schedule", "day");

    add_response(({ "驗糧", "稱重", "大糧倉", "受潮" }),
        "方平斗一探筒插進米袋，捻起米粒道：「入倉官糧半點不得馬虎！若是青河連雨導致米粒受潮發霉，不僅不能入常平窖，還得發回重新烘曬！」");
}
