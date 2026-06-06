// Room: /open/main/room/d9.c

inherit ROOM;

void create ()
{
  set ("short", "沙漠");
	set( "build", 60 );
  set ("long", @LONG
這兒是一望無際的撒哈拉沙漠，東北有一棟建築依勢而建，
從這兒看過去, 卻看不到入口, 不知它的門是在哪一邊?
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/center/npc/loto" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"r2",
  "north" : __DIR__"d2",
  "west" : __DIR__"d8",
  "east" : __DIR__"r1",
]));

  setup();
}
