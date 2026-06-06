inherit ROOM;
void create() {
	set( "short", "浪子居正殿" );
	set( "object", ([
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount5"  : 1,
		"file10"   : "/open/tendo/obj/chaosbelt",
		"amount6"  : 1,
		"file5"    : "/daemon/class/fighter/figring",
		"amount9"  : 1,
		"amount10" : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"amount2"  : 1,
		"file9"    : "/daemon/class/blademan/obj/shield",
		"amount7"  : 1,
		"file2"    : "/open/mon/obj/ghost-cloak",
		"amount4"  : 1,
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"file6"    : "/open/wind-rain/obj/sun_red_cloth",
		"file8"    : "/open/mogi/castle/obj/lochagem",
		"file3"    : "/open/wu/npc/obj/armband",
	]) );
	set( "owner", "roar" );
	set( "light_up", 1 );
	set( "build", 12380 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room365",
		"west"      : "/open/clan/13_luck/room/room103.c",
		"out"       : "/open/clan/13_luck/room/room86.c",
		"east"      : "/open/clan/13_luck/room/room117.c",
		"north"     : "/open/clan/13_luck/room/room186",
	]) );
	set( "long", @LONG
屋頂寶紅色的琉璃瓦被炙熱的陽光照的閃閃發亮，兩旁兩頭巨大的石獅子，
鎮守著『浪子居』的正門。向內望去，你不經嚇了一跳，內部的裝潢擺設不輸給
當今的帝都。大殿的上首佇立著一道人影，這人讓人有莫名的敬畏感，其全身散
發著強烈的刀王霸氣。這股霸氣足以稱傲笑整個武林，不對任何人服輸。他到底
是誰？他就是浪子居的主人，讓武林人士聞風喪膽的刀王--風魔浪子。
LONG);
	setup();
	replace_program(ROOM);
}
