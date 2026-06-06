// Room: /open/death/house1.c

inherit ROOM;

void create()
{
	set("short", "鬼屋");
	set("long", "
這是一間什麼都沒有的房間。
");

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"eroad",
]));
  set("light_up", 1 );
  set("no_magic", 1 );
  set("no_fight", 1 );

	setup();
}
