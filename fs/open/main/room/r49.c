// Room: /open/main/room/r49.c

inherit ROOM;

void create ()
{
  set ("short", "黃土小路");
	set( "build", 12 );
  set ("long", @LONG
這裡已經離中土有點距離了，雖然還在王朝的管轄範圍，
可是在此出了事可難期望王朝給的保護. 這你似乎有盜賊出沒
，你得自己小心. 道路在此呈東西走.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"L21",
  "west" : __DIR__"r48",
  "south" : __DIR__"f31",
]));

  set("outdoors", "/open/main");

  setup();
}
