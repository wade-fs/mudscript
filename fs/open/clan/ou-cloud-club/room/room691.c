inherit ROOM;
void create() {
	set( "short", "$HBWHT$$WHT$楓映天蓮劍$NOR$" );
	set( "object", ([
		"amount7"  : 1,
		"file1"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount1"  : 1,
		"file9"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount2"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/obj/fon-sky-sword",
		"file7"    : "/open/magic-manor/obj/fon-sky-sword",
		"file2"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount4"  : 1,
	]) );
	set( "owner", "cowboy" );
	set( "build", 10102 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room692",
		"west"      : "/open/clan/ou-cloud-club/room/room690.c",
	]) );
	set( "long", @LONG

$WHT$楓映天蓮劍楓映天蓮劍楓映天蓮劍楓映天蓮劍$NOR$
$WHT$楓映天蓮劍楓映天蓮劍楓映天蓮劍楓映天蓮劍$NOR$
$WHT$楓映天蓮劍楓映天蓮劍楓映天蓮劍楓映天蓮劍$NOR$
$WHT$楓映天蓮劍楓映天蓮劍楓映天蓮劍楓映天蓮劍$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
