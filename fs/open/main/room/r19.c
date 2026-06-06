// Room: /open/main/room/r19.c

inherit ROOM;

void create ()
{
  set ("short", "道路");
	set( "build", 36 );
  set ("long", @LONG
這裡是從驛站通往北盧關必經的要道, 往南就是中央驛站, 人來人
往, 在這兒似乎還可以聽到聲音.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : "/open/main/room/F12",
  "north" : "/open/main/room/r12",
  "south" : "/open/center/room/road1",
]));

  set("outdoors", "/open/main");

  setup();
}
