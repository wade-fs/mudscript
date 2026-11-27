// /d/routes/forest_landslide.c
// 東線第二段 (seg_city_panmu, 260里) 節點 2：南嶺林海官道・滑坡搶通段

#include "/include/ansi.h"
#include "/include/globals.h"

inherit ROUTE_ROOM_OB;

void create() {
    ::create();
    set_route_segment("seg_city_panmu");
    set_node_index(2);
    set_short("南嶺林海官道・滑坡搶通段");
    set_long("官道行至此處，東側山坡因金石商會越界濫伐古冷杉導致水土流失，大面積\n"
             "黃泥夾雜著斷裂樹根傾瀉而下，掩埋了半幅路面。百工木作與護路民夫已在泥濘中\n"
             "鋪設了成排的枕木棧橋，供重載大車緩慢輾過。向南退回【南嶺林海驛】，往西北\n"
             "穿出林海邊緣即可抵達金石府城南郊的【南嶺官道匯流口】。\n");

    set_exits(([
        "south":     "/d/routes/forest_sea_post.c",
        "northwest": "/d/city/outer/south_road.c",
    ]));

    set_coordinate(2, 9, 0);
}
