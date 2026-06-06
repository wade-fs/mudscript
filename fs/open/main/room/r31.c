// Room: /open/main/room/r31.c

inherit ROOM;

void create ()
{
	set("short","道路");
	set( "build", 1 );
  set ("long", @LONG
這是一條青石板鋪成的道路 , 是朝廷近幾年新開闢的 , 通往
大陸南方的城市 , 關卡 , 你發現路上商人特別多 , 不知是何緣
故 , 北方就是中央驛站了 , 你可以在那裡休息一下 .

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/center/room/road3",
  "south" : __DIR__"r33",
]));

  set("outdoors", "/open/main");


  setup();
}
