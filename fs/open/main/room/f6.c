// Room: /open/main/room/F6.c

inherit ROOM;

void create ()
{
  set ("short", "密林");
  set ("long", @LONG
這裡一望無際的密林，四週伸手只見四指, 可見其黑的程度。南邊高高聳立著
一座高山, 山頂不知是雲還是雪, 一片白茫茫, 那裡難道是蜀山?
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"F3",
  "west" : __DIR__"F5",
  "east" : __DIR__"s4",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/obj/g_item" :1,
  "/open/main/npc/tiger" : 1,
]));

  setup();
}
