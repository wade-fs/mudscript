// d/city/gate/gate_south.c
// 金石府城・南關城門 (重型貨車與黑石鋪南方動脈入口)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石府城・南關城門");
    set_long("高達三丈的青石條石拱券城門森嚴厚重，外側橫跨著兩丈深的寬闊護城壕溝。\n"
             "此處是金石都城正南咽喉要塞，扼守通往盤木縣、重石縣與極南黑石鋪之商道。\n"
             "門邊立著一座巨型重車生鐵地磅 (scale)，幾名披甲稅吏手按鐵戟，嚴密盤查往來大車與流民。\n"
             "往南沿驛道可通往南嶺官道 (south_road)，向北穿過城門則進入城內大石堆棧，\n"
             "西邊有一間低矮的車馬小棧供流民歇腳，拾石階而上 (up) 可登上巡城青石步道。\n");

    set_exits(([
        "south": "/d/city/outer/south_road.c",
        "north": "/d/city/south/yard_material.c",
        "west":  "/d/city/gate/gate_south_inn.c",
        "up":    "/d/city/wall/wall_path_s.c",
    ]));

    set("is_outdoor", 1);
    set("gate_id", "south");
    spawn_npc("/clone/npc/city_gate_guard.c");
    spawn_npc("/clone/npc/gate_south_taxofficer.c");
}

int can_receive(object ob) {
    if (!ob || !userp(ob)) return 1;
    // 往南出城無條件允許
    string last_loc = ob->query_temp("last_location");
    if (last_loc && strsrch(last_loc, "/d/city/") != -1 && strsrch(last_loc, "/outer/") == -1) {
        return 1;
    }
    object city_d = load_object(CITY_D);
    if (city_d) {
        mapping res = city_d->check_gate_access(ob, "south");
        if (!res["allow"]) {
            tell_object(ob, HIR + res["msg"] + "\n" NOR);
            return 0;
        } else if (res["fee"] > 0) {
            tell_object(ob, YEL + res["msg"] + "\n" NOR);
        }
    }
    return 1;
}
