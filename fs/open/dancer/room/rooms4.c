// Room: /open/dancer/room/rooms4.c :cgy
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set( "build", 12 );
  set ("long", @LONG
夜夢小築的走廊，向北連接到練舞場，兩旁的牆上雕塑著許多舞
者翩翩起舞的優美姿態，讓你不禁駐足觀賞，心中不由暗讚雕塑者的
神奇技巧，令人嘆為觀止。向南可到玄關，離開夜夢小築。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/dancer/room/rooms3.c",
  "south" : "/open/dancer/room/rooms5.c",
]));

  set("light_up", 1);

  setup();
}
