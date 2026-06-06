#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "迴廊");
  set ("long", @LONG
這裡是一條迴廊, 往東南前往段王府的武器室, 而往兩旁也各有
一條走道 ,迴廊上鋪著上好的大紅地毯, 襯托出一股莊嚴的氣氛。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"np32",
  "west" : __DIR__"np1",
  "north" : __DIR__"np15",
]));
  set("light_up", 1);

  setup();
}

int valid_leave(object me, string dir)
{
         if( dir=="southeast" && me->query("family/family_name")!="段家" )
         if(!wizardp(me))
      return notify_fail(HIC + "洋蔥小丸子" + NOR + "似笑非笑的對你說: 不給進。\n");
        return ::valid_leave(me, dir);
}

