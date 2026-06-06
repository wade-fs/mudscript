inherit ROOM;
void create() {
	set( "short", "『青石官道』" );
	set( "owner", "mill" );
	set( "object", ([
		"file7"    : "/open/prayer/obj/girl-neck",
		"file2"    : "/open/mogi/dragon/obj/sunblade",
		"amount7"  : 1,
		"file8"    : "/open/mogi/dragon/obj/dragonar",
		"amount6"  : 1,
		"file6"    : "/open/prayer/obj/girl-wrists",
		"file5"    : "/open/mogi/dragon/obj/hounghe",
		"amount8"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/beggar/obj/shield",
		"amount1"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/beggar/obj/legs",
		"amount5"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/mogi/dragon/obj/sunblade",
	]) );
	set( "build", 10142 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room471.c",
	]) );
	set( "long", @LONG

     這是一條寬敞堅實的青石板大道﹐大道兩旁有很多商家﹐從這裡往西
 通往洛陽城外的華山，往北通往驛站，往東則是通往洛陽城的廣場。這是
 一條寬敞堅實的青石板大道﹐大道兩旁有很多商家﹐從這裡往西通往洛陽
 城外的華山，往北通往驛站，往東則是通往洛陽城的廣場。

LONG);
	setup();
	replace_program(ROOM);
}
