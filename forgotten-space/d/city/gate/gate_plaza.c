// d/city/gate/gate_plaza.c
// 金石府城・北關前校場

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("北關門內・前校場");
    set_long("北關城門內側一片以黃土夯實的巨大操演校場。\n"
             "場地兩側擺放著整齊的兵器架與鹿砦拒馬，一面高聳的軍令木牌懸掛在旗桿下，\n"
             "貼滿了邊防衛所與府衙的緝捕急令。值役副將正在此督操換防衛士。\n"
             "向北穿過拱券即為北關城門，往南大道通往百工總會街口，\n"
             "東面是一家喧鬧的關外車馬店，西面則是存放官方查扣貨物的官道大貨棧。\n");

    set_exits(([
        "north": "/d/city/gate/gate_north.c",
        "south": "/d/city/north/gong_gate.c",
        "east":  "/d/city/gate/gate_inn.c",
        "west":  "/d/city/gate/gate_warehouse.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", WHT "校場碎石夯土地面硬如鐵板，場邊拴馬樁木皮被牲口啃得毛糙。" NOR);
    set_smell("default", YEL "車馬塵土、牲口草料與北關貨棧飄來的生鐵礦砂味。" NOR);
    set_listen("default", HIY "車夫吆喝牲口進棧卸貨的喊聲與官兵巡場踏步聲此起彼落。" NOR);

    spawn_npc("/clone/npc/gate_plaza_deputy.c");
}
