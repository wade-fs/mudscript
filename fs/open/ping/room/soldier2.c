// Room: /open/ping/room/soldier2.c
inherit ROOM;

void create ()
{
  set ("short", "練兵場");
  set ("long", @LONG
你來到平南駐軍的練兵場,許多士兵們正努力的操練著,為
保家護國供獻他們的青春,你不禁對他們的精神感到欽配.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/soldier1" : 1,
]));
  set("outdoors", "/open/ping");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"road10",
  "south" : __DIR__"soldier3.c",
  "east" : __DIR__"soldier1",
]));

  setup();
}
