inherit ROOM;
void create() {
	set( "short", "$HIG$波-武器室(12)$NOR$" );
	set( "object", ([
		"amount7"  : 99999,
		"amount8"  : 99999,
		"file9"    : "/open/killer/obj/bellstar",
		"amount3"  : 99999,
		"amount1"  : 99999,
		"file7"    : "/open/killer/obj/bellstar",
		"amount5"  : 99999,
		"amount6"  : 99999,
		"file4"    : "/obj/gift/xisuidan",
		"file3"    : "/open/killer/obj/bellstar",
		"file5"    : "/open/killer/obj/bellstar",
		"amount2"  : 99999,
		"file1"    : "/open/killer/obj/bellstar",
		"amount9"  : 99999,
		"file10"   : "/obj/gift/shenliwan",
		"amount4"  : 1,
		"amount10" : 1,
		"file2"    : "/open/killer/obj/bellstar",
		"file8"    : "/open/killer/obj/bellstar",
		"file6"    : "/open/killer/obj/bellstar",
	]) );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room385",
		"west"      : "/open/clan/ou-cloud-club/room/room318.c",
		"east"      : "/open/clan/ou-cloud-club/room/room257.c",
	]) );
	set( "owner", "perth" );
	set( "build", 36288 );
	set( "long", @LONG
室武器室武器室武器室武器室武器室武器室
武器室武器室武器室武器室武器室武器室武器室
武器室武器室武器室武器室武器室武器室武器室
武器室武器室武器室武器室武器室武器室武器室
武器室武器室武器室武器室武器室武器室武器室
武器室武器室武器室武器室武器室武器室武器室

LONG);
	setup();
	replace_program(ROOM);
}
