// Room: /open/main/room/s26.c

inherit ROOM;

void create ()
{
  set ("short", "草原");
  set ("long", @LONG
這裡是一片草原，割人的野草凌亂的長著，高高低低的芒
穗隨著風起伏，這裡應該有不少動物躲藏.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/center/npc/brownhorse" : 1,
]));
  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"s30",
  "north" : __DIR__"f21",
  "east" : __DIR__"s27",
]));

  setup();
}
