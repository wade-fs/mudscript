inherit ROOM;
void create() {
	set( "short", "$HIR$火靈焰扇$NOR$" );
	set( "object", ([
		"amount7"  : 1,
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount2"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount4"  : 1,
	]) );
	set( "owner", "cowboy" );
	set( "build", 10663 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room695",
		"west"      : "/open/clan/ou-cloud-club/room/room693.c",
	]) );
	set( "long", @LONG

$HIR$火靈焰扇火靈焰扇火靈焰扇火靈焰扇火靈焰扇$NOR$
$HIR$火靈焰扇火靈焰扇火靈焰扇火靈焰扇火靈焰扇$NOR$
$HIR$火靈焰扇火靈焰扇火靈焰扇火靈焰扇火靈焰扇$NOR$
$HIR$火靈焰扇火靈焰扇火靈焰扇火靈焰扇火靈焰扇$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
