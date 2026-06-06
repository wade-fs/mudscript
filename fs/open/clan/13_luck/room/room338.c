inherit ROOM;
void create() {
	set( "short", "百草道" );
	set( "owner", "smalloo" );
	set( "object", ([
		"amount7"  : 1,
		"file1"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount6"  : 1,
		"file7"    : "/open/magic-manor/obj/golden-ball",
		"amount5"  : 1,
		"file3"    : "/open/magic-manor/obj/wood-ball",
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/obj/soil-ball",
		"amount1"  : 7,
		"amount8"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/magic-manor/obj/golden-ball",
		"amount9"  : 1,
		"file9"    : "/open/magic-manor/obj/fire-ball",
		"file6"    : "/open/magic-manor/obj/golden-ball",
		"file2"    : "/open/magic-manor/obj/wood-ball",
		"file8"    : "/open/magic-manor/obj/water-ball",
		"amount10" : 1,
		"file10"   : "/open/magic-manor/obj/fire-ball",
		"amount2"  : 1,
	]) );
	set( "build", 11610 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room337",
		"north"     : "/open/clan/13_luck/room/room339.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    你突然眼前一亮，見青青翠谷，滿點綴著或紅或紫，或黃或白的
鮮花。你一路行來，遍地都是樹木花草，此處竟是一個花花麗麗的世
界，你在此處，受益良多，百花百草好像有治療的功用讓你身心覺舒
坦，好像所有的疼痛都不見了，收穫不少。


LONG);
	setup();
	replace_program(ROOM);
}
