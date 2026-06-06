// Room: /u/e/eiei/room/troom_3a_1.c
inherit ROOM;

void create ()
{
  set ("short", "殘破青石路");
  set ("long", @LONG
    走到這裡，樹林似乎更冒密了。不過如果你仔細看
    的話，在路的一旁好像有一條青石板鋪成的的小路，雖
    然看起來青石板已經有點老舊，不過由於青石板一直向
    樹林裡面延伸，所以看起來就顯的有一點突出了。
LONG);

  set("objects", ([ /* sizeof() == 1 */
]));
  set("outdoors", "/u/e/eiei/room");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"troom_3a_2.c",
  "west" : __DIR__"troom_3a.c",
]));

  setup();
}
