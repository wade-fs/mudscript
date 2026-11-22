// d/city/south/warehouse_shang.c
// 商會一至三號大庫 (丁鐵鎖庫頭、三號暗庫走私密箱)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石商會・一至三號大庫");
    set_long("這座深院高牆的條石巨庫分為一至三號三座連排大倉，儲備全城進出大宗貨物與稅關暫存。\n"
             "一號庫堆滿青河藥材，二號庫碼放盤木巨木，而最深處的三號暗庫則掛著雙重精鋼鐵鎖。\n"
             "商會庫頭丁鐵鎖牽著兩頭兇悍巡夜惡犬在廊下巡視，嚴防外人窺探三號庫內的走私密箱。\n"
             "向北穿過石拱門，可回到遠行車馬大院。\n");

    set_exits(([
        "north": "/d/city/south/caravan_yard.c",
    ]));

    set("is_outdoor", 0);

    set_touch("default", WHT "商會密庫石壁厚實冷硬，貨架上的封蠟箱籠摸起來緊實沉重。" NOR);
    set_smell("default", YEL "熟革、松脂火漆與各縣運抵之冷杉木料混雜出的深沉庫房味。" NOR);
    set_listen("default", WHT "守衛與庫房管事沿貨架巡檢的沉穩腳步聲與木箱封釘輕響。" NOR);

    spawn_npc("/clone/npc/warehouse_shang_chief.c");
}
