// Room: /open/capital/room/r45.c

inherit ROOM;

void create()
{
	 set("short","日升馳道");
	set("long",@LONG
城東的車馬大道。為了便於軍隊快速通行而設。地面鋪的石板相當
考究，有許多精巧的花紋，有獅頭，有雙龍搶珠圖。不過年代已久，又
有車馬來回碾壓的緣故，許多石板都出現裂痕。
   
LONG);
  set("outdoors", "/open/capital" );
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r44",
  "north" : __DIR__"r46",
]) );

  set("gopath", "south" );

  setup();
}
