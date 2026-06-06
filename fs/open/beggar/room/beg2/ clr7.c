// Room: /u/g/guetenr/beggar/room/beg2/ clr7.c
inherit ROOM;

void create ()
{
  set ("short", "空房間");
  set ("long", @LONG
這是一間什麼都沒有的房間。
LONG);

  set("outdoors", "/open/");
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"clr6",
]));

  setup();
}
