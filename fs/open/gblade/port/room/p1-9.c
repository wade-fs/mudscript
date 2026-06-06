// Room: /open/gblade/port/room/p1-9.c
inherit ROOM;

void create ()
{
  set ("short", "石板大道");
  set ("long", @LONG
道路延伸到此已進入了城郊 , 路上行人也少了許多 , 只有
幾個刀客在此行走著 , 與一般刀客不同的是 , 他們人人配戴著
一把黃金小刀 , 衣著華麗 , 看來 , 江湖三大門派之一的金刀門
必在附近 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"p1-7",
  "east" : __DIR__"p1-10.c",
]));
set("objects",([
	"/open/gblade/port/npc/trainee":1,
	]));

  setup();
}
