// Room: /u/g/guetenr/beggar/room/beg1/room11.c
inherit ROOM;

void create ()
{
  set ("short", "道路");
  set ("long", @LONG
這是一條人煙稀少的小路,直直的往東西走去,誰也不知道他通
到哪裡去。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room10.c",
  "west" : __DIR__"room12.c",
]));
  set("outdoors", "/open/");

  setup();
}
