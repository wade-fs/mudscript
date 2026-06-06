inherit ROOM;
void create() {
	set( "short", "魚龍室" );
	set( "owner", "kaien" );
	set( "object", ([
		"file4"    : "/open/mogi/dragon/obj/power",
		"amount9"  : 1,
		"file7"    : "/open/magic-manor/obj/soil-ball",
		"file2"    : "/open/snow/obj/stone",
		"amount4"  : 1,
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"amount7"  : 1,
		"file1"    : "/open/ghost-hole/obj/light-spirit",
		"amount2"  : 1,
		"amount1"  : 1,
	]) );
	set( "build", 10170 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room347.c",
		"south"     : "/open/clan/13_luck/room/room346",
		"west"      : "/open/clan/13_luck/room/room350.c",
		"north"     : "/open/clan/13_luck/room/room353.c",
		"east"      : "/open/clan/13_luck/room/room351.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    一進入此室中，只見牆上掛著一把魚龍(Ublade)，刀上刻著一些
細細小小的字，仔細看去原來是魔刀『三斬歸元』刀法之一，妳運用
九地之氣，使出【三斬歸元～魚龍嗜元】『魚龍毒鴆～～煌嵐叢滅』
祕咒語音猶在耳，霎那間，從魚龍竄出九彩煙霧，瞬時邊旁周圍的生
物死之殆盡。你運氣於刀，暗使真元，只見刀騰空飛出，直奔皇宮禁
衛軍的胸膛。你吸收滿天毒霧運氣於刀，霎那間手中刀刃散發出驚人
駭毒，籠罩四方。


LONG);
	setup();
	replace_program(ROOM);
}
