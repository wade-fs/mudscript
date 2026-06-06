// Room: /open/capital/room/r20.c

inherit ROOM;

void create()
{
	set("short","日落廣場");
	set("long",@LONG
一個中型的廣場。往南去是一條很寬的車馬大道，往北去是條一般
大小的胡同。廣場上有尊前朝忠臣的雕像，雕像四週圍繞著小販，這兒
俗稱西市。雖然比不上東市，但相去不遠，而且這兒最有名的是算命攤
子，一排全部都是，有摸骨的有測字的，千奇百怪，至於可信度就見人
見智了。

LONG);

  set("outdoors", "/open/capital" );

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r21",
  "north" : __DIR__"r19",
]) );

  set("gopath", "north" );

  setup();
}
