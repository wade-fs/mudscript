// Room: /open/capital/room/r70.c

inherit ROOM;

void create ()
{
  set ("short", "中央街口");
	set( "build", 159 );
  set ("long", @LONG
這裡是一個交叉路口，在你的西邊是芝麻胡同，東邊則是蘿蔔胡同
。蘿蔔胡同內有著遠近馳名的悅來客棧及城內最大的當鋪，芝麻胡同內
則有王安食堂及乾記商行。

LONG);

  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"h12",
  "south" : __DIR__"r71",
  "north" : __DIR__"r69",
  "east" : __DIR__"h13",
]));

  setup();
}
