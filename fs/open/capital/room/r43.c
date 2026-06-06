// Room: /open/capital/room/r43.c

inherit ROOM;

void create()
{
        set("short", "日升馳道");
        set("long",@LONG
城東的車馬大道。為了便於軍隊快速通行而設。地面鋪的石板相當
考究，聽說是把從蜀山採得的大石塊加以研磨成一塊塊的石板，再由雕
刻匠在上面雕製花紋，然後再平鋪而成。

LONG);



  set("outdoors", "/open/capital" );

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r44",
  "south" : __DIR__"r42",
]) );

  set("gopath", "south" );

  setup();
}
