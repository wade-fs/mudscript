inherit ROOM;
void create() {
	set( "short", "$BBLU$奧$BGRN$利$BCYN$凡$BMAG$德$NOR$" );
	set( "owner", "soilclaw" );
	set( "object", ([
		"amount9"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"amount6"  : 1,
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount3"  : 1,
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount8"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"file1"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount2"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount10" : 1,
		"amount4"  : 1,
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
	]) );
	set( "build", 10492 );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room47",
	]) );
	set( "long", @LONG
奧利凡德是賣魔杖的商店,而店名就是店長的名字,奧利凡德先生專門
製作魔杖且販賣,他記得他所賣出的每一根魔杖,
店內有位霍格華茲的新生正要買魔杖,只見奧利凡德不斷的換魔杖
給新生試用,據奧利凡德的說法,與其說是巫師選購魔杖,
倒不如說是魔杖選擇了它的主人

LONG);
	setup();
	replace_program(ROOM);
}
