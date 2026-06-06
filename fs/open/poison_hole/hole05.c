// Room: /u/w/whatup/poison_hole/hole01.c
inherit ROOM;

void create ()
{
  set ("short", "山洞");
  set ("long", @LONG
一進山洞裡，前面隱隱約約的出現人影，但你什麼也看不清楚。遠
方也傳來陣的聊天聲。
LONG);
set("no_transmit", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/killer.c" : 1,
]));
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"hole04.c",
  "west" : __DIR__"hole08.c",
  "south" : __DIR__"hole06.c",
  "north" : __DIR__"hole07.c",
]));

  setup();
}
