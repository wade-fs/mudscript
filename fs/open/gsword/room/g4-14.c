// Room: /open/gsword/room/gsword6-1.c
inherit ROOM;

void create ()
{
  set ("short", "小橋");
  set ("long", @LONG
你正站在一做石橋上 ,兩排低低的欄竿護著橋上之人不致落水 ,幾隻鴛
鴦悠游於橋下 ,觸手可及 .

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/npc/trainee-7.c" : 1,
]));

  set("light_up", 1);
  set("outdoors", "/open/gsword/room");

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/gsword/room/g4-16.c",
  "east" : "/open/gsword/room/g4-7.c",
]));

  setup();
}
