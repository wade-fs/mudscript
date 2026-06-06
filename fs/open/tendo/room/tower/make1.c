inherit ROOM;
void create()
{
	set("short", "大松樹");
	set("long", @LONG
你現在正攀附在一株大松樹的樹幹上，這裡離地面已經有七、八丈
高，如果不小心跌了下去，不斷條腿也得去半條命，松樹上結了許多毬
果，不過大部分都離樹幹很遠，你搆不到。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : "/open/tendo/room/tower/make2",
  "down" : "/open/tendo/room/tower/tomb",
]));
       set("outdoors",1);
	setup();

}


