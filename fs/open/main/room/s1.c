// Room: /open/main/room/s1.c

inherit ROOM;

void create ()
{
  set ("short", "草原");
	set( "build", 24 );
  set ("long", @LONG
這裡是大草原的西邊, 往西邊看過去, 是黑壓壓的密林, 也充滿許多不
思議的怪物, 還是少進去為妙
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/center/npc/brownhorse" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"F3",
  "south" : __DIR__"s4",
  "east" : __DIR__"s2",
]));

  setup();
}
