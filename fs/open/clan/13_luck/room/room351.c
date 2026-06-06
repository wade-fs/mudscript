inherit ROOM;
void create() {
	set( "short", "雪影室" );
	set( "owner", "kaien" );
	set( "object", ([
		"file3"    : "/daemon/class/blademan/obj/iceblade",
		"file4"    : "/daemon/class/blademan/obj/six-neck",
		"file8"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount3"  : 1,
		"amount4"  : 1,
		"amount8"  : 1,
	]) );
	set( "build", 10614 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room352",
	]) );
	set( "long", @LONG

    一進入此室中，只見牆上掛著一把雪影(Iceblade)，刀上刻著一
些細細小小的字，仔細看去原來是魔刀『三斬歸元』刀法之一妳施展
九人之氣，使出【三斬歸元～雪影化元】『狂龍怒震～～雪影寒霜』
妳運起真元，手持雪影往天一揮，頓時，山搖地動，風雲變色，以擾
亂了四季的運轉，蒼天突然地飄下漫天雪彩。漫天雪彩，只見皇宮禁
衛軍看的失魂，已被刀刃所傷。手中刀刃，似有似無，編織漫天雪彩
，只見皇門守衛困在其中。

LONG);
	setup();
	replace_program(ROOM);
}
