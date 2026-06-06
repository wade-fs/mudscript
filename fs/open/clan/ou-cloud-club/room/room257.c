inherit ROOM;
void create() {
	set( "short", "$HIM$粉筆$HIW$之$HIG$家$NOR$" );
	set( "owner", "perth" );
	set( "object", ([
		"amount2"  : 1,
		"file6"    : "/obj/gift/shenliwan",
		"file8"    : "/open/scholar/obj/s_hands",
		"file1"    : "/obj/gift/shenliwan",
		"file10"   : "/obj/gift/unknowdan",
		"amount8"  : 1,
		"amount7"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"file5"    : "/open/gblade/obj/sa-head",
		"amount4"  : 1,
		"amount6"  : 1,
		"file9"    : "/obj/gift/xiandan",
		"file3"    : "/obj/gift/xisuidan",
		"amount5"  : 1,
		"file2"    : "/obj/gift/unknowdan",
		"file4"    : "/obj/gift/unknowdan",
		"amount3"  : 1,
		"file7"    : "/obj/gift/xiandan",
		"amount9"  : 1,
	]) );
	set( "build", 10025 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room389",
		"east"      : "/open/clan/ou-cloud-club/room/room248.c",
	]) );
	set( "long", @LONG
粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家
粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家
粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家
粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家
粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家
粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家
粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家
粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家
粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家粉筆的家
LONG);
	setup();
	replace_program(ROOM);
}
