// Room: /open/ping/room/soldier4
inherit ROOM;

void create ()
{
  set ("short", "大營");
	set( "build", 75 );
  set ("long", @LONG
你走進了一座樸素的帳棚裡,雄雄的爐火在棚中點著,書卷,
兵器隨地的擺著,棚中還擺著一張檀木桌,這的主人必然不講就
生活.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"soldier3",
]));
  set("objects", ([
      "/open/ping/npc/general.c" : 1,
     ]) );
  set("light_up", 1);

  setup();
}
