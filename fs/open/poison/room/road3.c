// Room: /open/main/room/f10.c

inherit ROOM;

void create ()
{
  set ("short", "林中小徑");
	set( "build", 12 );
  set ("long", @LONG
你走在一條不知名的林中小徑上，兩旁住著一些以此森
林為生的散戶，附近盡是高大的林木，遠方傳來陣陣的流水
聲，這裡十分的清靜。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : "/open/poison/room/room4",
  "north" : "/open/poison/room/room3",
  "east" : "/open/poison/room/road2",
  "southwest" : "/open/poison/room/road4",
]));
  set("outdoors", "/open/main");

  setup();
}
