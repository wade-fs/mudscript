// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
  set ("short", "學堂");
  set ("long", @LONG
這裡是楓林港一家頗具規模的學堂 . 這家學堂是公家的 , 
為大財主史懷恩所捐獻 . 許多楓林的居民都曾在此接受過基本
教育 .  

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"r3-3",
]));

  setup();
}
int valid_leave(object me, string dir)
{
if(dir == "up")
if (me->query("id") != "guilty")
     return notify_fail("那個房間只有儒門弟子才能進去。\n");
     return :: valid_leave(me, dir);
}
