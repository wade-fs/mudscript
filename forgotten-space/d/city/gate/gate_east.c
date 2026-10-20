// d/city/gate/gate_east.c
// 金石府城・東關城門 (礦產、硫礬與黑市貨流通道)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石府城・東關城門");
    set_long("東關城門背靠大荒東麓，外通烈礬縣明礬赤銅礦區與濁水縣沼澤浮橋。\n"
             "空氣中飄散著微弱的酸苦硫磺焦味與潮濕泥土氣息。城門口設有地火稅卡，\n"
             "東關督稅官手持硃砂筆，對運抵的生銅與硃砂晶石嚴格秤重抽成。\n"
             "往西穿過城門便進入鎮武軍鎮區外轅門，拾階而上 (up) 可登上東城烽燧步道。\n");

    set_exits(([
        "west": "/d/city/east/wu_gate.c",
        "up":   "/d/city/wall/wall_path_e.c",
    ]));

    set("is_outdoor", 1);
    set("gate_id", "east");
    spawn_npc("/clone/npc/city_gate_guard.c");
    spawn_npc("/clone/npc/gate_east_taxchief.c");
}
