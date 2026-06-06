// Room: /u/m/moner/open/room/r10.c 
inherit ROOM;
 
void create ()
{
  set ("short", "走廊");
  set ("long", @LONG

    這裡是風行山寨的走廊, 北邊就是大廳了, 兩旁牆壁上整齊的掛著
兩排火把, 火光照的你兩頰紅紅的。


LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room14.c",
  "out" : __DIR__"r11.c",
]));

  setup();
  replace_program(ROOM);
}
