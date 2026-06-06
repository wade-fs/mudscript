// Room: /open/main/room/s24.c

inherit ROOM;

void create ()
{
  set ("short", "草原");
  set ("long", @LONG
這裡是一片草原，割人的野草凌亂的長著，高高低低的芒
穗隨著風起伏，這裡應該有不少動物躲藏.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/npc/bear" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"s23",
  "south" : __DIR__"L14",
  "east" : __DIR__"s25",
]));

  setup();
}
