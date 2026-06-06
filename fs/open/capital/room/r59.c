// Room: /open/capital/room/r59.c

inherit ROOM;

void create ()
{
  set ("short", "雲洋街口");
	set( "build", 60 );
  set ("long", @LONG
這兒便是京城裡達官貴人的住所, 平常人是不會到雲洋大街這兒來
逗留的。在你的北方有一座高臺, 是皇帝做為祭祀、昭告的所在, 平常的時
候也可以看到皇上登上高臺, 眺望遠景, 飲酒作詩。
    往南的中央大道正是京城最繁榮的地帶，所有的商店均可由此街道
連接起來，如果你想好好的逛逛的話, 往南走就對了, 南方盡頭處就是
鎮南門。

LONG);

	set("objects", ([ /* sizeof()==1 */
	"/open/capital/npc/cleanman" : 1
]) );

  set("exits", ([ /* sizeof() == 5 */
  "west" : __DIR__"r58",
  "south" : __DIR__"r66",
  "north" : __DIR__"r74",
  "east" : __DIR__"r60",
  "northup" : __DIR__"tower",
]));
  set("outdoors", "/open/capital");

  setup();
}
