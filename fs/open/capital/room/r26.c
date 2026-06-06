// Room: /open/capital/room/r26.c

inherit ROOM;

void create()
{
	set("short","日落馳道");
	set( "build", 12 );
	set("long",@LONG
城西的車馬大道。路邊的兩排大榕樹枝葉茂密，看起來似乎年代久
遠，據附近的長者說，這些樹至少有百年歷史了，歷經了好幾代的皇帝
，看過無數世間冷暖。

LONG);


  set("outdoors", "/open/capital" );

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r27",
  "north" : __DIR__"r25",
]) );

  set("gopath", "north" );

  setup();
}
