// Room: /open/main/room/gy2.c
inherit ROOM;

void create ()
{
  set ("short", "扶桑軍營");
  set ("long", @LONG
你來到了扶桑的軍營，意外的發現他們在此當根據地，切莫隨意
    行動，以免橫屍荒野。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/npc/officer2.c" : 2,
]));
  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"gy1.c",
  "enter" : __DIR__"gy3.c",
]));

  setup();
}
int valid_leave(object me, string dir)
{
   if(dir=="enter"&&present("guard",environment(me))) 
{
    if(!me->query_temp("allow-enter"))
    return notify_fail("看來你無法往這個方向移動。\n");
}
return 1;
}
