// Room: /open/ping/room/road2.c
inherit ROOM;

void create ()
{
  set ("short", "石板大道");
  set ("long", @LONG
這裡就是平南鬧區了,平南城雖地處偏疆,可是中土有的東西
,這裡也樣樣都有,運氣好的話,你還可以買到苗疆的特產呢 !!你
的北方是一家客棧,南方則是一家商行.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/man.c" : 1,
]));
  set("outdoors", "/open/ping");
  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"road3.c",
  "north" : __DIR__"pinghotel",
  "south" : __DIR__"pingshop",
  "east" : __DIR__"road1",
]));

  setup();
}
