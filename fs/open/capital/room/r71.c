// Room: /open/capital/room/r71.c

inherit ROOM;

void create ()
{
  set ("short", "中央大街");
	set( "build", 49 );
  set ("long", @LONG
    走在京城的中央大街, 街上不時有快馬奔過, 顯示出這條街交通的
繁忙。這裡是整個京城的南方, 街道雖不似北邊的富豪住宅般華麗, 但
也有另一股風味, 住的都是一些中下等的居民, 雖不富有但卻勤奮, 顯
的生氣勃勃。路的西邊是皇上特設的考場。路的東邊則是賞金兌換處。



LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"test_room",
  "north" : __DIR__"r70",
  "south" : __DIR__"r72",
  "east" : __DIR__"head_room",
]));
  set("outdoors", "/open/capital");

  setup();
}
