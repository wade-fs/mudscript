// clone/npc/granary_liubingzhong.c
// 劉秉忠・常平倉大使 (granary_liubingzhong) - 官平糧倉

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("劉秉忠");
    set_short(CYN "常平倉大使" NOR " 劉秉忠");
    set_long("一位身穿深青官袍、手持算籌與糧冊的清廉老官吏。\n"
             "他終日守在府城戰略常平倉前，監看米糧出入，隨時準備在災荒糧價暴漲時開倉平糶。\n");
    set_id(({ "granary_liubingzhong", "liubingzhong", "liu bingzhong", "granary commissioner", "劉秉忠", "常平倉大使", "倉大使" }));

    setup_archetype("A", 25);
    set("class", "mortal");
    set("faction", "yamen");
    set("roles", ({ "service", "info" }));
    set("rules", ([ "price_cap_trigger": 250, "stabilize_mult_min": 70, "stabilize_mult_max": 90 ]));
    set("schedule", "day");

    add_response(({ "常平倉", "平糶", "糧價", "開倉", "災荒" }),
        "劉秉忠撫摸著糧冊肅然道：「民以食為天！常平倉儲備全府三年戰略荒糧，一旦市井糧價衝破兩成半（250%）上限，本官即刻奏請開倉平糶，將米價壓回七至九折！」");
}
