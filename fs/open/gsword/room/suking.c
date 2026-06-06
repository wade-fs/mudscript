// Room: /open/gsword/room/suking.c

inherit ROOM;

void create ()
{
  set ("short", "將軍府");
	set( "build", 116 );
  set ("long", @LONG
這裡是前朝舊宮蜀中府,在本朝成立後,首都遷往新都京城,
這裡便從權力中心退位,成為本城平西大將軍的居所, 你仍可從
那高聳的圍牆,深遠的大院,想像過去的富麗與堂皇.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/gsword/room/su4",
  "enter" : __DIR__"suking1",
]));

  set("light_up", 1);

  setup();
}
