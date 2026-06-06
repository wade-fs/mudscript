// Room: /open/tendo/room/t07.c

inherit ROOM;

void create()
{
	set("short", "回歸之門");
	set("long", @LONG
在牆上有著一個十分巨大的太極圖，使的這裡的磁場受到改變，
當使出回歸術時便可感受到這裡所發出的力量，而不至於迷失方向。
若元神修練有成，也就是到達了半仙的境界，在死亡之時元神也會受
到這兒的吸引而不至墜入冥界，故冥界之人一直對此地虎視眈眈，隨
時要摧毀此地。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"t06",
]));
       set("objects",([
	"/open/tendo/npc/chinho" : 1,
       ]));
	set("light_up",1);
	setup();
}
