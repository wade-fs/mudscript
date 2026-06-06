#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "迴廊");
	set( "build", 2 );
  set ("long", @LONG
走進這裡, 有一個轉角, 往北是三師兄段遠風的住處, 而往東則
是休息室, 長廊上鋪著上好的大紅地毯, 襯托出一股莊嚴的氣氛。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"np15",
  "west" : __DIR__"np13",
  "north" : __DIR__"np19",
  "east" : __DIR__"np18",
]));
  set("light_up", 1);

  setup();
}

int valid_leave(object me, string dir)
{
         if( dir=="east" && me->query("family/family_name")!="段家" )
      return notify_fail(HIC"洋蔥小丸子"NOR"似笑非笑的對你說: 不給進。\n");
        return ::valid_leave(me, dir);
}

