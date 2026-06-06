// Room: /open/gblade/port/room/p1-7.c
inherit ROOM;

void create ()
{
  set ("short", "石板大道");
  set ("long", @LONG
這是一條石板鋪成的大道 , 路上行人大都配戴著一把刀 ,
似乎人人都帶著武功 , 看來你還是少在這兒惹事為妙 ,北邊
是一家武器店 , 專賣各種刀器 ,南邊是防具店 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"p1-8.c",
  "north" : __DIR__"p1-6.c",
  "west" : __DIR__"p1-4",
  "east" : __DIR__"p1-9.c",
]));
	set("objects",([
	"/open/gblade/port/npc/blademan2":1,
	]));

  setup();
}
