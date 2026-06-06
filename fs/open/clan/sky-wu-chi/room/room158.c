inherit ROOM;
void create() {
	set( "short", "龍極殿" );
	set( "owner", "cong" );
	set( "object", ([
		"amount4"  : 1,
		"file8"    : "/open/gblade/obj/sa-head",
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount5"  : 1,
		"amount3"  : 1,
		"file6"    : "/open/mon/obj/thousand-nectar",
		"amount9"  : 50,
		"amount8"  : 1,
		"file10"   : "/open/doctor/pill/ice_pill",
		"amount2"  : 1,
		"amount10" : 248,
		"file9"    : "/open/fire-hole/obj/y-pill",
		"amount1"  : 35,
		"file1"    : "/open/fire-hole/obj/b-pill",
		"amount7"  : 30,
		"file7"    : "/open/fire-hole/obj/r-pill",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"amount6"  : 15,
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "light_up", 1 );
	set( "build", 11680 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room46",
		"west"      : "/open/clan/sky-wu-chi/room/room194.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"east"      : "/open/clan/sky-wu-chi/room/room30.c",
	]) );
	set( "long", @LONG
這裡是幫主的臥室 當你一走進這裡時你突然被一陣鋒利的刀氣給
嚇得不知道如何是好 而這些刀氣就是平常幫主所修煉出來的
他不但修為以到達天人進界 所以有如此強烈的刀氣
所以此房間不是人人可以進入的 必須要有一定的修為才行 
LONG);
	setup();
	replace_program(ROOM);
}
