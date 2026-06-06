// Room: /open/capital/room/r24.c

inherit ROOM;

void create ()
{
  set ("short", "日落馳道");
	set( "build", 24 );
  set ("long", @LONG
東邊有條小路啣接在馳道上。路旁立了根小木牌上面寫著『芙蓉湖』
。正想著要不要過去瞧瞧的同時，有一群水鳥從湖的方向飛向天際，更
加使你有去瞧瞧這湖的衝動。

LONG);

  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"r25",
  "north" : __DIR__"r23",
  "east" : __DIR__"lake1",
]));
  set("gopath", "north");

  setup();
}
