// Room: /open/ping/room/pinghotel.c
inherit ROOM;

void create ()
{
  set ("short", "平南客棧");
  set ("long", @LONG
這裡是平南城最大的客棧,許多旅客都在這裡修息,你也可以
在這裡買些小吃,填飽你饑腸碌碌的肚子.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road2",
]));
  set("light_up", 1);

  setup();
}
