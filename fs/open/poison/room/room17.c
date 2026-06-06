// Room: /open/poison/room/room17
inherit ROOM;

void create ()
{
  set ("short", "魔殿側殿");
  set ("long", @LONG
這裡是冥蠱魔教的側殿，這裡連同正殿，擺設許多奇花
異木，散發出陣陣迷人的清香，大殿內前有一黃金爐，黃金
爐內飄來陣陣麝檀香，整個魔殿香煙裊裊的，如夢如幻。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room1",
  "down" : __DIR__"coolroom",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/right_hufa" : 1,
]));
  set("light_up", 1);

  setup();
}
int valid_leave(object me, string dir)
{
if (dir == "down" && !me ->query("mark/love",1) )
     return notify_fail("未經允許\不得進入！ \n");
     return :: valid_leave(me, dir);
}

