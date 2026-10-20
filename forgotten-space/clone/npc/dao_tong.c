// clone/npc/dao_tong.c
// 清茗・司香道童 (dao_quiet_incense) - 宣道司靜心聽經閣掌香道童

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("清茗道童");
    set_short(WHT "宣道司司香道童" NOR " 清茗");
    set_long("一位頭挽雙髻、神色恬靜的年輕道童，正手持沉香線香添入香爐。\n"
             "道童輕聲道：「若市井紅塵濁氣迷心，可在聽經閣靜坐 (meditate) 一個時辰，消耗 50 文香油錢清除 50 點濁氣。」\n");
    set_id(({ "dao_quiet_incense", "dao_tong", "qingming", "incense boy", "daoist boy", "清茗道童", "司香道童", "道童" }));

    setup_archetype("G", 8);
    set("class", "dao_initiate");
    set("faction", "dao");
    set("roles", ({ "service", "info" }));
    set("rules", ([ "cleanse_turbidity": 50, "fee_copper": 50 ]));
    set("schedule", "24h");

    add_response(({ "聽經", "濁氣", "淨化", "香油", "靜坐" }),
        "清茗道童合十道：「添香油五十文，靜坐調息 (meditate)，道音繚繞，自可蕩除五十點心魔濁障。」");
}
