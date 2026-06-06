// Room: /open/capital/room/tower
inherit ROOM;

void create ()
{
  set ("short", "高臺");
	set( "build", 12 );
  set ("long", @LONG
一登上高臺, 你才發現上面非常的寬闊, 地面上的石板成放射狀排
列, 有如十二道光芒從中央的祭台發射出去。因為這兒是整個京城最高
的地方, 因此你可以毫無困難的俯視整個京城, 到處人車往來, 十分繁
忙, 京城外是一遍青青草原, 微風吹來, 便似一道道的波浪襲來, 景觀
壯麗。

LONG);

  set("light_up", 1);
  set("capital_thief", 1);
  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"r08",
  "southdown" : __DIR__"r59",
]));

  setup();
}
