// Room: /open/death/nroad.c

inherit ROOM;

void create ()
{
  set ("short", "閻羅北路");
  set ("long", @LONG

這是一間什麼都沒有的房間。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : "/open/death/office",
  "west" : "/open/death/bank.c",
  "south" : "/open/death/square",
  "east" : "/open/death/blackshop",
]));

  set("light_up", 1 );
  set("no_magic", 1 );
  set("no_fight", 1 );

  setup();
}
