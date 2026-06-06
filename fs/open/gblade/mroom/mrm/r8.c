// Room: /u/m/moner/room/room9.c
inherit ROOM;

void create ()
{
  set ("short", "長廊");
  set ("long", @LONG

走進這裡, 是一條長廊, 往前通往馬房,而往兩旁也各有一條走道,長廊上鋪著上
好的紅毯, 兩旁的牆上掛著幾盞油燈。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"r4.c",
  "west" : __DIR__"r6.c",
  "south" : __DIR__"r3.c",
]));
  set("light_up", 1);

  setup();
}
