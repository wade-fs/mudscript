// d/city/gate/gate_warehouse.c
// 金石府城・官道大貨棧 (大宗貨物過磅與查扣)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("北關門側・官道大貨棧");
    set_long("這座高大幽深的條石倉庫由府衙與金石商會共管。\n"
             "四周堆疊著數以百計的生漆重木貨箱與麻袋，貼著鮮紅的封條。\n"
             "幾名倉管書吏手持賬簿，正會同商會驗貨掌櫃逐一核對自極北運抵的獸皮與風蝕石英。\n"
             "往東可步出貨棧大門，回到北關前校場。\n");

    set_exits(([
        "east": "/d/city/gate/gate_plaza.c",
    ]));

    set("is_outdoor", 0);

    set_touch("default", WHT "堆滿檢驗貨箱的木棚乾燥微涼，驗貨官手中的鐵籤摸上去光滑冰冷。" NOR);
    set_smell("default", YEL "生鐵、麻袋、桐油防水布與六縣雜貨混雜的貨倉味道。" NOR);
    set_listen("default", WHT "鐵籤戳進貨包檢查夾帶的「嚓」聲與驗貨書吏核對清單的報數聲。" NOR);

    spawn_npc("/clone/npc/gate_warehouse_assessor.c");
}
