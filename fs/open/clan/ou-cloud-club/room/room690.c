inherit ROOM;
void create() {
	set( "short", "$GRN$幔羅刀無影$NOR$" );
	set( "object", ([
		"amount7"  : 1,
		"file1"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount1"  : 1,
		"file9"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount2"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file7"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file2"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount4"  : 1,
	]) );
	set( "owner", "cowboy" );
	set( "build", 11165 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room691",
		"west"      : "/open/clan/ou-cloud-club/room/room689.c",
	]) );
	set( "long", @LONG

$GRN$幔羅刀無影幔羅刀無影幔羅刀無影幔羅刀無影$NOR$
$GRN$幔羅刀無影幔羅刀無影幔羅刀無影幔羅刀無影$NOR$
$GRN$幔羅刀無影幔羅刀無影幔羅刀無影幔羅刀無影$NOR$
$GRN$幔羅刀無影幔羅刀無影幔羅刀無影幔羅刀無影$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
