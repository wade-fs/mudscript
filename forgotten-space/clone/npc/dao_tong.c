// clone/npc/dao_tong.c
// 司香道童 - 宣道司靜心閣掌香道童

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("司香道童");
    set_short(WHT "宣道司" NOR " 司香道童");
    set_long("一位頭挽雙髻、神色恬靜的年輕道童，正手持沉香線香添入香爐。\n"
             "道童輕聲道：「若市井紅塵濁氣迷心，可在聽經閣靜坐 (meditate) 一個時辰，消耗 50 文香油錢清除 50 點濁氣。」\n");
    set_id(({ "dao_tong", "tong", "daoist boy", "司香道童", "道童" }));

    set_level(10);
    recalc_stats();

    add_response(({ "聽經", "濁氣", "淨化", "香油" }),
        "道童合十道：「添香油五十文，靜坐調息 (meditate)，道音繚繞，自可蕩除心魔濁障。」");
}
