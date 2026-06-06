// Room: /open/main/room/m18.c

inherit ROOM;

void create()
{
	set("short", "丘陵");
	set( "build", 36 );
	set("long", @LONG
你現在在一座土丘上頭, 微微的風輕拂著你, 這裡什
麼都沒有, 有著只是茫茫的蘆花和藍天。
    往北通往交通大道，往東邊和南邊看去仍舊是一片丘
陵。西邊有條馬路往上爬可以爬上天山山脈，那邊似乎是
聞名遐邇的少室峰。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"m27",
  "northdown" : __DIR__"r29",
  "east" : __DIR__"m19",
  "westup":__DIR__"M16",
]) );

  set("outdoors", "/open/main" );


  setup();
}
