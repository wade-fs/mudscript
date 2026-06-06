inherit ROOM;
void create() {
	set( "short", "保命小屋" );
	set( "owner", "panhermes" );
	set( "light_up", 1 );
	set( "object", ([
		"amount5"  : 149,
		"file7"    : "/open/mon/obj/ghost-cloak",
		"amount3"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"file3"    : "/open/mon/obj/ghost-helmet",
		"amount6"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/mon/obj/mon-pill",
		"amount7"  : 1,
		"file4"    : "/open/killer/obj/atman_pill",
		"file9"    : "/open/mon/obj/ghost-legging",
		"file8"    : "/open/tendo/obj/chaosbelt",
		"amount2"  : 2052,
		"file5"    : "/open/fire-hole/obj/w-pill",
		"amount8"  : 1,
		"file6"    : "/open/mogi/castle/obj/lochagem",
		"file10"   : "/daemon/class/blademan/obj/shield",
		"file1"    : "/daemon/class/fighter/figring",
		"amount4"  : 265,
	]) );
	set( "build", 10048 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room352.c",
		"south"     : "/open/clan/sky-wu-chi/room/room354.c",
		"north"     : "/open/clan/sky-wu-chi/room/room353.c",
		"down"      : "/open/clan/sky-wu-chi/room/room175.c",
		"west"      : "/open/clan/sky-wu-chi/room/room355",
	]) );
	set( "long", @LONG
這是專門放保命ㄉ小裝備
全都是機器人一號ㄉ生活必需品也就是練功ㄉ小配備
如玲瓏靴,魔法盾,幸運草環,陽炎臂環,妖行甲,
寒冰,血龍鞭,冰雪神戒,菩提袈裟........等等
一些放不上檯面ㄉ裝備,偶爾有放ghost eq 等等
不過他ㄉ希望是能拿一套save eq @@
所以他在等好心人士ㄉ施捨
LONG);
	setup();
	replace_program(ROOM);
}
