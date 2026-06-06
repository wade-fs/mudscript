// by roger
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short","芙蓉湖旁");
set ("long", @LONG
    沿岸榴花似火，楑柳成蔭，遠山近水，漠漠如煙。在這大城裡，
是活力的泉源，暮氣的蒸籠，既是功名的溫床，也是罪惡的淵藪；是
英雄得志之地，亦是志士頹靡之所，好漢落魄的地方。
LONG);


  set("exits", ([
            "east"  : __DIR__"room2",
            "west"  : __DIR__"room4",
                ]));

       

        setup();
}
