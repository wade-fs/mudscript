inherit ROOM;

void create ()
{
  set ("short", "草原");
	set( "build", 12 );
  set ("long", @LONG
這裡是一望無際的大草原，地上有不少野獸的足跡
西北方可通往廣大的蒙古高原，但你得先有辦法爬上去。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/center/npc/blackhorse" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 4 */
  "northwest" : "/open/grassland/entrance1",
  "south" : __DIR__"s5",
  "west" : __DIR__"s1",
  "east" : __DIR__"s3",
]));

  setup();
}
