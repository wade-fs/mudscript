// Room: /open/main/room/d1.c

inherit ROOM;

void create()
{
	set("short", "沙漠");
	set( "build", 60 );
	set("long", "這裡是撒哈拉沙漠的西邊, 往西看過去是一片綠油油的草原, 
偶而有也獸出沒, 炙熱的天氣, 來到這兒彷彿看到老家似的溫馨。
");

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"s3",
  "south" : __DIR__"d8",
  "east" : __DIR__"d2",
]) );

  set("outdoors", "/open/main" );


  setup();
}
