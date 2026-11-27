// d/city/north/gong_gate.c
// 府城百工總會外門 (物道世俗門戶)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("百工總會・外門坊口");
    set_long("此處是一座以巨型齒輪與青銅滑輪裝飾的奇特青石牌坊。\n"
             "牌坊正中橫懸「巧奪造化」四個精銅大字，四周傳出節奏紛繁的鍛鐵、鋸木與碾石聲。\n"
             "行會知事鐵尺公手持銅尺立於坊下，審查往來學徒與各縣採辦匠籍資質。\n"
             "向南直通中央青石廣場，往北進入北關前校場，\n"
             "向東是匠籍登記處，往西則步入百工總會萬機正堂。\n");

    set_exits(([
        "south": "/d/city/center/square.c",
        "north": "/d/city/gate/gate_plaza.c",
        "east":  "/d/city/north/gong_registry.c",
        "west":  "/d/city/north/gong_hall.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", HIY "牌坊『巧奪造化』精銅底座被學徒撫摸得溫潤發亮，地面青石沾著木屑與鐵粉。" NOR);
    set_smell("default", YEL "煤煙鐵腥、新鮮木材松脂與熬製鞣革硝水的複合百工工坊味。" NOR);
    set_listen("default", HIY "鍛鐵的叮噹、拉大鋸的「呼哧」聲與雕鑿青石的清脆叩擊聲合奏出全城最忙碌的樂章。" NOR);

    spawn_npc("/clone/npc/gong_gate_tiechigong.c");
}
