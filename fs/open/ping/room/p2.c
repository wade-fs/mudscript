// Room: /open/ping/room/p2
inherit ROOM;

void create ()
{
  set ("short", "長廊");
  set ("long", @LONG
走進這裡, 是一條長廊, 往前通往大廳, 而往兩旁也各有一條走道
長廊上鋪著上好的大紅地毯, 襯托出一股莊嚴的氣氛。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"p1",
  "west" : __DIR__"p3",
  "out" : __DIR__"pingking",
  "east" : __DIR__"p5",
]));
  set("light_up", 1);

  setup();
}

int valid_leave(object me, string dir)
{
         if( dir=="east" && me->query("family/family_name")!="段家" )
         if(!wizardp(me))
      return notify_fail("洋蔥小丸子似笑非笑的對你說: 不給進。\n");
        return ::valid_leave(me, dir);
}

