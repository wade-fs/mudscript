// Room: /open/main/room/d8.c

inherit ROOM;

void create()
{
	set("short", "沙漠");
	set( "build", 60 );
	set("long", "這裡是撒哈拉沙漠的西邊, 往西看過去是一片綠油油的草原, 
偶而有也獸出沒, 炙熱的天氣, 來到這兒彷彿看到老家似的溫馨。
");

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"s9",
  "west" : __DIR__"s6",
  "north" : __DIR__"d1",
  "east" : __DIR__"d9",
]) );

  set("outdoors", "/open/main" );


  setup();
}
