// Room: /open/badman/room/t6.c

inherit ROOM;

void create ()
{
  set ("short", "地道");
  set ("long", @LONG
你走到了地道的盡頭，微弱的光線從洞口射了進來，但是仍然
無法讓你看清這四周，還是趕快先離開這個陰森的地道吧。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/badman/room/t5",
  "out" : "/open/badman/room/b0",
]));

  setup();
}
