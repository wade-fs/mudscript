// by roger && taifar
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short",HIW"雅奕座"NOR);
set ("long", @LONG
懸燈萬盞千華於上，映於水面粼粼波光，又倒映在一山一木一石一
葉，襯得白玉鑿座更增雪豔，座周圍均以綠草為地，以碎石為綴，
種以圃花闊添視野，香風縈迴，葉聲低吟。白玉雕座圍圓，石弈桌
為中心，是好弈人士的情鄉。
LONG);



  set("exits", ([
            "east"  : __DIR__"80",
            "west"  : __DIR__"79",
                ]));

        setup();
}
