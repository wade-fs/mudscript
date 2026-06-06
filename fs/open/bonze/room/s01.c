// Room: /open/soulin/room/s01
inherit ROOM;

void create ()
{
  set ("short", "少林寺前廣場");
  set ("long", @LONG
	
寺前一片廣大的空地，為平常時寺內弟子練武之所在。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"s04.c",
  "east" : __DIR__"s02.c",
  "west" : __DIR__"s32.c",
]));
  set("outdoors", "/open/soulin");
  set("objects", ([ /* sizeof() == 1 */
  "/open/bonze/npc/l_monk" : 2,
]));
  

  setup();
}
