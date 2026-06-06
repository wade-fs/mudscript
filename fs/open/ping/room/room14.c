// Room: /u/m/moner/open/room/room14.c 
inherit ROOM;
 
void create ()
{
  set ("short", "走廊");
  set ("long", @LONG

    這裡是風行山寨的走廊, 北邊就是大廳了, 兩旁牆壁上整齊的掛著
兩排火把, 火光照的你兩頰紅紅的。


LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"r9.c",
  "south" : __DIR__"r10.c",
  "east" : __DIR__"r7.c",
]));

  setup();
  replace_program(ROOM);
}
