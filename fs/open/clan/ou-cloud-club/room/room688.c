inherit ROOM;
void create() {
	set( "short", "$CYN$化劫菱歸真$NOR$" );
	set( "object", ([
		"amount7"  : 1,
		"file1"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount1"  : 1,
		"file9"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount2"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"file7"    : "/open/magic-manor/obj/hwa-je-icer",
		"file2"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount4"  : 1,
	]) );
	set( "owner", "cowboy" );
	set( "build", 13574 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room689",
		"west"      : "/open/clan/ou-cloud-club/room/room687.c",
	]) );
	set( "long", @LONG

$CYN$化劫菱歸真化劫菱歸真化劫菱歸真化劫菱歸真$NOR$
$CYN$化劫菱歸真化劫菱歸真化劫菱歸真化劫菱歸真$NOR$
$CYN$化劫菱歸真化劫菱歸真化劫菱歸真化劫菱歸真$NOR$
$CYN$化劫菱歸真化劫菱歸真化劫菱歸真化劫菱歸真$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
