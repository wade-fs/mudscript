// by roger && taifar
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short","迴翡小逕");
set ("long", @LONG
堆石為桓或編花為門，一徑引入著璧桃花， 兩邊郁有西府海棠，其  
勢若傘，絲垂金縷，葩吐丹砂，不遠，薔薇高架綠藤盤錯，轉過花
障，則見青溪前阻，翠松扶天玉蘭繞砌，上面龍蟠螭護，下面玲瓏
鑿就，妝若瑤池。
LONG);



  set("exits", ([
            "north" : __DIR__"61",
            "south" : __DIR__"74",
                ]));
  set("objects", ([ 
  __DIR__"npc/wind-guard-out" : 3,
                  ])); 
        setup();
}
