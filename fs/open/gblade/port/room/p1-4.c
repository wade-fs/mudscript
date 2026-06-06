// Room: /open/gblade/port/room/p1-4.c
inherit ROOM;

void create ()
{
  set ("short", "石板大道");
  set ("long", @LONG
這是一條石板鋪成的大道 , 路上行人大都配戴著一把刀 ,
似乎人人都帶著武功 , 看來你還是少在這兒惹事為妙 , 北邊
一棟平房 , 一些刀客進進出出的 , 也許你該過去瞧瞧看 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"p1-5.c",
  "west" : __DIR__"p1-3",
  "east" : __DIR__"p1-7.c",
]));
	set("objects",([
	"/open/gblade/port/npc/blademan":1,
	]));

  setup();
}
