// Room: /open/tendo/room/t06.c

inherit ROOM;

void create()
{
	set("short", "修行房");
	set("long", @LONG
草蓆上擺放著許許多多的蒲團，一位天道的老者
坐在正前方講解天道法術和老莊的思想。不少的天道
弟子和遠道前來求仙的人，正坐在這裡心無旁貸地聽
講，似乎完全沒注意到你的出現。

LONG
	);
	set("objects",([
	"/open/tendo/npc/chin" : 1,
	"/open/tendo/npc/truin" : 1,
	"/open/tendo/npc/gechin" : 1,
	]));
	set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"t12",
]));
	set("light_up",1);
	setup();
}
