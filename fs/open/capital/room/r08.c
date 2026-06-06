// Room: /open/capital/room/r08.c

inherit ROOM;

void create ()
{
  set ("short", "環宮大道");
	set( "build", 264 );
  set ("long", @LONG
往北是進出皇宮的唯一通道, 但若不是什麼皇親國戚或是文武百官
等大人物, 是不准平常老百姓進出的。南方有道樓梯, 直通一座高臺,
是皇帝祭祖、昭告的地方, 你想上去瞧瞧嗎?

LONG);

  set("outdoors", "/open/capital");
  set("objects", ([ /* sizeof() == 2 */
  "/open/capital/npc/cleanman" : 1,
  "/open/start/npc/any" : 1,
]));
  set("exits", ([ /* sizeof() == 5 */
  "north" : __DIR__"D04",
  "west" : __DIR__"r07",
  "southup" : __DIR__"tower",
  "east" : __DIR__"r09",
  "south" : __DIR__"r74",
]));
  set("gopath", "east");

  setup();
}
