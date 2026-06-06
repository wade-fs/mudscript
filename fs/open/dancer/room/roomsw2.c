// Room: /open/dancer/room/roomsw2.c :cgy

inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
夜夢小築的走廊，東邊可到練舞場，南北兩旁的牆上雕塑著許多
美麗的雕像，令你不禁駐足觀賞，向西則是夢月閣想要生上的必需品
的話就到那吧……

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : "/open/dancer/room/roomsw1.c",
  "west" : "/open/dancer/room/roomsw3.c",
]));

  set("light_up", 1);

  setup();
}
