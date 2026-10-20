// d/city/gate/gate_north.c
// 金石府城・北關城門 (官道終點、邊軍扣關防線)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石府城・北關城門");
    set_long("此處是金石都城最戒備森嚴的軍事門戶，城牆足有三丈五尺厚，以生鐵重釘加固。\n"
             "往北直通鎮風要塞與極北荒原天風谷，官道兩側插滿了黑底金字的府城軍旗。\n"
             "城門典吏韓清按刀端坐於公案後，審核往來客商路引與軍備情報。\n"
             "向北出城可通往外城大車馬店，西北小徑蜿蜒通往亂葬義塚，\n"
             "向南進入北關前校場，拾級而上 (up) 則可登上巡城北步道與北城望荒箭樓。\n");

    set_exits(([
        "north":     "/d/city/outer/post_depot.c",
        "south":     "/d/city/gate/gate_plaza.c",
        "northwest": "/d/city/outer/graveyard.c",
        "up":        "/d/city/wall/wall_path_n.c",
    ]));

    set("is_outdoor", 1);
    set("gate_id", "north");
    spawn_npc("/clone/npc/city_gate_guard.c");
}

int can_receive(object ob) {
    if (!ob || !userp(ob)) return 1;
    string last_loc = ob->query_temp("last_location");
    if (last_loc && strsrch(last_loc, "/d/city/") != -1 && strsrch(last_loc, "/outer/") == -1) {
        return 1;
    }
    object city_d = load_object(CITY_D);
    if (city_d) {
        mapping res = city_d->check_gate_access(ob, "north");
        if (!res["allow"]) {
            tell_object(ob, HIR + res["msg"] + "\n" NOR);
            return 0;
        } else if (res["fee"] > 0) {
            tell_object(ob, YEL + res["msg"] + "\n" NOR);
        }
    }
    return 1;
}
