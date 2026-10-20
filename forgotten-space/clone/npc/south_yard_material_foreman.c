// clone/npc/south_yard_material_foreman.c
// 石大柱・堆棧把頭 (south_yard_material_foreman) - 大木大石初堆棧

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("石大柱");
    set_short(YEL "初堆棧把頭" NOR " 石大柱");
    set_long("一位膀大腰圓、手拿粗麻號子旗的苦力把頭，正指揮腳夫將重石縣條石與盤木縣原木卸車初裁。\n");
    set_id(({ "south_yard_material_foreman", "shi dazhu", "foreman shi", "石大柱", "堆棧把頭" }));

    setup_archetype("K", 15);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "service", "info" }));
    set("schedule", "day");

    add_response(({ "毛料", "條石", "原木", "初切", "重石" }),
        "石大柱吼了一嗓子號子道：「盤木縣的百尺鐵力木和重石縣的千斤條石太沉，進城會壓壞青石街面，全得在咱這初堆棧過磅初切，再分運去北城百工坊！」");
}
