// by roger && taifar
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short",HIY"湜雨廳"NOR);
	set( "build", 3 );
set ("long", @LONG
四面皆是雕空玲瓏木，或流雲百蝠，或歲寒三友，或山水人物，或
翎毛花卉，或集錦，或博古，或萬福萬壽，均是名手雕縷，五彩鑲
金崁玉的。一格一格，或儲書設鼎，或安硯置墨，或供瓶安景，式
樣或方或圓，或葵花蕉葉，或連環半壁，柳椅聯成三方一應向外，
是為湜雨。
LONG);



  set("exits", ([
            "south" : __DIR__"52",
            "north" : __DIR__"50",
            "east"  : __DIR__"59",
            "west"  : __DIR__"64",

                ]));
  set("objects", ([ 
  __DIR__"npc/yu-ting" : 1,
                  ]));
       
        setup();
}
