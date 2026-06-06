inherit ROOM;
void create() {
	set( "short", "$HIR$火靈焰扇$NOR$" );
	set( "object", ([
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"amount2"  : 1,
		"amount7"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount9"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount10" : 1,
		"amount4"  : 1,
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount5"  : 1,
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount3"  : 1,
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount8"  : 1,
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
	]) );
	set( "build", 10246 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room476",
		"east"      : "/open/clan/ou-cloud-club/room/room478.c",
	]) );
	set( "long", @LONG
焰扇火靈焰扇火靈焰扇火靈焰扇火靈焰扇火靈焰扇
火靈焰扇火靈焰扇火靈焰扇火靈焰扇火靈焰扇火靈焰扇
火靈焰扇火靈焰扇火靈焰扇火靈焰扇火靈焰扇火靈焰扇
火靈焰扇火靈焰扇火靈焰扇火靈焰扇火靈焰扇火靈焰扇
火靈焰扇火靈焰扇火靈焰扇火靈焰扇火靈焰扇火靈焰扇
火靈焰扇火靈焰扇火靈焰扇火靈焰扇火靈焰扇火靈焰扇

LONG);
	setup();
	replace_program(ROOM);
}
