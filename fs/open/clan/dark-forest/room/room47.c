inherit ROOM;
void create() {
	set( "short", "冰淇淋五號" );
	set( "object", ([
		"file1"    : "/obj/stone/suipian",
		"amount1"  : 2,
	]) );
	set( "build", 10019 );
	set( "owner", "mika" );
	set( "exits", ([
		"south"     : "/open/clan/dark-forest/room/room44",
	]) );
	set( "long", @LONG
冰淇淋五號冰淇淋五號冰淇淋五號冰淇淋五號冰淇淋五號
    冰淇淋五號冰淇淋五號冰淇淋五號冰淇淋五號冰淇淋五號
    冰淇淋五號冰淇淋五號冰淇淋五號冰淇淋五號冰淇淋五號
    冰淇淋五號冰淇淋五號冰淇淋五號冰淇淋五號冰淇淋五號
    冰淇淋五號冰淇淋五號冰淇淋五號冰淇淋五號冰淇淋五號
    冰淇淋五號冰淇淋五號冰淇淋五號冰淇淋五號冰淇淋五號
    冰淇淋五號冰淇淋五號冰淇淋五號冰淇淋五號冰淇淋五號
LONG);
	setup();
	replace_program(ROOM);
}
