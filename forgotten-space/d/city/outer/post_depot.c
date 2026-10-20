// d/city/outer/post_depot.c
// 金石府外・外城大車馬店

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("外城近郊・大車馬店");
    set_long("北關外這座佔地數畝的巨大牲口棚搭著厚厚的茅草棚頂。\n"
             "空氣中瀰漫著濃烈的乾草料與馬糞騷氣，上百匹自極北荒原與六縣歸來的挽馬馱獸正在槽前咀嚼。\n"
             "幾名黑臉馬伕正手腳麻利地卸套刷馬、添水加料。\n"
             "向南穿過驛道土埕，便是威武肅穆的金石北關。\n");

    set_exits(([
        "south": "/d/city/gate/gate_north.c",
    ]));

    set("is_outdoor", 1);
}
