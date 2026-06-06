// Room: /open/capital/room/h11.c

inherit ROOM;

void create ()
{
  set ("short", "芝麻胡同");
	set( "build", 12 );
  set ("long", @LONG
這裡種了一棵大樹, 樹蔭籠罩了整條大街, 因此附近的居民在中午
大太陽的時候都喜歡搬個椅子到樹下坐坐, 聊聊天, 生活還挺愜意的樣
子。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"h10",
  "east" : __DIR__"h12",
]));
  set("outdoors", "/open/capital");

  setup();
}
