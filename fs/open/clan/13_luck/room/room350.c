inherit ROOM;
void create() {
	set( "short", "邪刀室" );
	set( "owner", "kaien" );
	set( "object", ([
		"file6"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount6"  : 1,
		"file1"    : "/open/main/obj/shiblade",
		"file10"   : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount4"  : 1,
		"amount10" : 1,
		"file8"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount1"  : 1,
		"file7"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount8"  : 1,
		"file4"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount7"  : 1,
	]) );
	set( "build", 10104 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room352",
	]) );
	set( "long", @LONG

    一進入此室中，只見牆上掛著一把 邪刀(Shi-blade)，刀上刻著一些
細細小小的字，仔細看去原來是魔刀『三斬歸元』刀法之一，妳聚集九天
之氣，使出【三斬歸元～邪龍斬元】『魔龍嗜血～～焚天邪月』，皇宮禁
衛軍驚愕之於，只見妳把邪刀插於地上，唸起秘咒，瞬時火燄歕張淹漫整
個天際。

LONG);
	setup();
	replace_program(ROOM);
}
