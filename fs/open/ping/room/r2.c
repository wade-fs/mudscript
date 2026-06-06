// Room: /u/m/moner/open/room/r2.c 
inherit ROOM;
 
void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
    這裡是風行山寨的走廊, 北邊就是大廳了, 兩旁牆壁上整齊的掛著
兩排火把, 火光照的你兩頰紅紅的。東邊有個出口通往玄關。


LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r1.c",
  "east" : __DIR__"r3.c",
]));

  setup();
  replace_program(ROOM);
}
