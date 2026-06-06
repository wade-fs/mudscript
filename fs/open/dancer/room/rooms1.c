// Room: /open/dancer/room/rooms1.c :cgy

inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set( "build", 36 );
  set ("long", @LONG
夜夢小築的走廊，向北連接到夜夢殿堂，兩旁的牆上雕塑著許多
舞者翩翩起舞的優美姿態，讓你不禁駐足觀賞，心中不由暗讚雕塑者
的神奇技巧，令人嘆為觀止。向南可到練舞場。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/dancer/room/start.c",
  "south" : "/open/dancer/room/rooms2.c",
]));

  set("light_up", 1);

  setup();
}
