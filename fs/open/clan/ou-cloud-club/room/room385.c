inherit ROOM;
void create() {
	set( "short", "$HIW$武器研發間(11)$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"amount10" : 1,
		"file5"    : "/obj/gift/unknowdan",
		"file2"    : "/open/killer/headkill/obj/world_dag",
		"file10"   : "/obj/gift/unknowdan",
		"amount2"  : 1,
		"file7"    : "/open/killer/headkill/obj/e_dag",
		"file8"    : "/open/killer/obj/black",
		"file9"    : "/open/killer/obj/bellstar",
		"file1"    : "/open/killer/headkill/obj/world_dag",
		"file3"    : "/open/killer/headkill/obj/world_dag",
		"amount8"  : 15,
		"amount4"  : 1,
		"amount9"  : 80000,
		"amount3"  : 1,
		"amount5"  : 1,
		"file4"    : "/open/killer/headkill/obj/world_dag",
		"file6"    : "/open/killer/headkill/obj/w_dag",
	]) );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room317",
		"south"     : "/open/clan/ou-cloud-club/room/room386.c",
		"north"     : "/open/clan/ou-cloud-club/room/room389",
	]) );
	set( "owner", "perth" );
	set( "build", 10308 );
	set( "long", @LONG
研發武器研發武器研發武器研發武器研發武器研發武器研發
武器研發武器研發武器研發武器研發武器研發武器研發武器研發
武器研發武器研發武器研發武器研發武器研發武器研發武器研發
武器研發武器研發武器研發武器研發武器研發武器研發武器研發
武器研發武器研發武器研發武器研發武器研發武器研發武器研發
武器研發武器研發武器研發武器研發武器研發武器研發武器研發

LONG);
	setup();
	replace_program(ROOM);
}
