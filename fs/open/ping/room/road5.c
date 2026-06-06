// Room: /open/ping/room/road5.c
inherit ROOM;

void create ()
{
  set ("short", "石板大道");
	set( "build", 231 );
  set ("long", @LONG
這裡是平南城的西區,每次苗人的進犯,這兒都是首當其衝,
然而這裡的百性似忽已習慣刀槍下過日子, 依然悠閒的作生意
,往南邊走就是平南城的驛站.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/man" : 1,
]));
  set("outdoors", "/open/ping");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"pingsteal",
  "west" : __DIR__"road6.c",
  "east" : __DIR__"road4",
  "south" : "/open/trans/room/room3",
]));

  setup();
}
