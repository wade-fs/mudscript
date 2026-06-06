// Room: /open/capital/room/r15.c

inherit ROOM;

void create ()
{
  set ("short", "東城門下");
	set( "build", 48 );
  set ("long", @LONG
這裡是兵馬常進出的地方，不要在此地逗留，以免遭受到不必要的
傷害，徒惹是非。
    西方的大道通往皇宮大門, 也可連至京城裡最富裕的區域。
    往北則是通往大理寺的路。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/soldier" : 1,
]));

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
   "north":"/open/capital/room/chen_home",
  "west" : __DIR__"r14",
  "east" : __DIR__"D02",
]));

  set("gopath", "west");

  setup();
}
