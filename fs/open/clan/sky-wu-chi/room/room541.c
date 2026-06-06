inherit ROOM;
void create() {
	set( "short", "你找死呀還不改" );
	set( "owner", "becy" );
	set( "light_up", 1 );
	set( "object", ([
		"file1"    : "/open/ping/questsfan/obj/paper1",
		"file3"    : "/open/mogi/dragon/obj/dragon-head",
		"amount8"  : 1,
		"amount9"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"amount1"  : 1,
		"file8"    : "/obj/gift/shenliwan",
		"file9"    : "/open/killer/obj/soul-hands",
		"amount7"  : 1,
		"amount10" : 1,
		"file5"    : "/open/capital/obj/4-4",
		"file7"    : "/open/killer/obj/soul-hands",
		"file10"   : "/open/magic-manor/obj/master_snake_head",
	]) );
	set( "build", 10003 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "long", @LONG
你是想死呀趕快給我想敘述你是想死呀趕快給我想敘述你是想死呀趕快給我想敘述
你是想死呀趕快給我想敘述你是想死呀趕快給我想敘述你是想死呀趕快給我想敘述
你是想死呀趕快給我想敘述你是想死呀趕快給我想敘述你是想死呀趕快給我想敘述
你是想死呀趕快給我想敘述你是想死呀趕快給我想敘述你是想死呀趕快給我想敘述
你是想死呀趕快給我想敘述你是想死呀趕快給我想敘述你是想死呀趕快給我想敘述
你是想死呀趕快給我想敘述你是想死呀趕快給我想敘述你是想死呀趕快給我想敘述
你是想死呀趕快給我想敘述你是想死呀趕快給我想敘述你是想死呀趕快給我想敘述
你是想死呀趕快給我想敘述你是想死呀趕快給我想敘述你是想死呀趕快給我想敘述
你是想死呀趕快給我想敘述你是想死呀趕快給我想敘述你是想死呀趕快給我想敘述
LONG);
	setup();
	replace_program(ROOM);
}
