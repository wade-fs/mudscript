// d/city/south/yard_material.c
// 大木大石初堆棧 (南關門內初切轉運)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("城南門內・大料初堆棧");
    set_long("此處是南關進城後大宗重料的第一落腳點，方圓數百丈堆滿了原木巨石。\n"
             "自重石縣運來的千斤條石與盤木縣的百年原木在此過磅初切，以減輕城內街道運載壓力。\n"
             "堆棧把頭手持紅漆墨斗穿梭指揮，鋸木與鑿石聲震耳欲聾。\n"
             "向南直通金石南關城門，往北走向六縣專材長街，往西穿過小巷則是官辦糧食市集。\n");

    set_exits(([
        "south": "/d/city/gate/gate_south.c",
        "north": "/d/city/south/market_special.c",
        "west":  "/d/city/south/grain_market.c",
    ]));

    set("is_outdoor", 1);
    spawn_npc("/clone/npc/south_yard_material_foreman.c");
}
