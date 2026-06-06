inherit ROOM;

void create ()
{
set("short","黃龍組");
	set( "build", 15 );
  set ("long", @LONG
這裡是殺手總壇的地下迷宮，也是由機關手諸岡渡所精心設置。
此處是黃龍組的組長渡永天工作的地方，並沒有很多的佈置
渡永天的身手，並不比葉秀殺弱，所以你想對他下手的話，最好小心一點
上方似乎有一個出口，可以跳出去，如果想離開可以試試。

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
"east" : __DIR__"sdr12.c",
"north" : __DIR__"sdr15.c",
"jump" : __DIR__"outr1.c",
]));
set("objects",([
"/open/killer/npc/hu_fa3.c":1,
]));
  setup();
}
