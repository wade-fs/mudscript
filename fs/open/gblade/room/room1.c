// Room: /u/m/moner/tree/room1.c
inherit ROOM;
void create ()
{
  set ("short", "迴廊");
	set( "build", 24 );
  set ("long", @LONG

你現在在迴廊上, 往北是一條小徑, 東西兩邊各有迴廊
通往東廂房與西廂房, 兩邊的欄干上雕刻著瑰麗的花紋,向南
可以回到密室。

LONG);

  set("exits", ([ /* sizeof() == 2 */
"south":__DIR__"secret.c",
  "north" : __DIR__"room2.c",
]));
  set("light_up", 1);

  setup();
}
