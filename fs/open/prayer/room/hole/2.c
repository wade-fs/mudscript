///open/prayer/room/hole/2.c

inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG

	走到洞口，一陣金鐵交擊之聲，在耳際鏗鏘作響，震的你心頭直打
	寒顫，聽說裡頭魔獸肆孽，能夠進來，未必能出的去，想想大好將
	來，是否該淌這趟渾水...........

LONG);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"1",
  "east":__DIR__"3",
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
	setup();
}
