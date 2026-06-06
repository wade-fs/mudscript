// Room: /u/g/guetenr/beggar/room/beg2/clr24.c
inherit ROOM;

void create ()
{
  set ("short", "西廂房");
  set ("long", @LONG
你看到一群乞丐圍在一起，並聽到鏗、鏗的聲音，你走近
一看，原來是他們正在玩骰子.....你想加入他們嗎？
LONG);

  set("outdoors", "/open/beggar");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"clr26.c",
  "south" : __DIR__"clr25.c",
  "east" : __DIR__"clr23.c",
]));

  setup();
}
