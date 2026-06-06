// Room: /open/gsword/room/g3-1.c
inherit ROOM;

void create ()
{
  set ("short", "僕人臥房");
  set ("long", @LONG
一間寬廣的大屋 ,一張好大的床從東自西 ,如果躺滿人的話 ,少說
也能睡個三四十個 ,房間中除了一張床外 ,別無它物 ,所有在仙劍派內
的長工 ,菜農 ,小童等 ,皆居於此 .

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/gsword/room/g3-2",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/npc/worker":1,
  "/open/gsword/npc/worker-1":1,
]));

  set("light_up", 1);

  setup();
}
