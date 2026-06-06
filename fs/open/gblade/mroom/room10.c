// Room: /u/m/moner/room/room10.c
inherit ROOM;

void create ()
{
  set ("short", "長廊");
  set ("long", @LONG

走進這裡, 是一條長廊, 往前通往後院, 而往兩旁也各有一條走道,長廊上鋪著上
好的紅毯, 兩旁的牆上掛著幾盞油燈。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room16.c",
  "north" : __DIR__"room13.c",
  "east" : __DIR__"room23.c",
  "northwest" : __DIR__"room2.c",
]));
  set("light_up", 1);

  setup();
}
