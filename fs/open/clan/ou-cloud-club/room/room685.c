inherit ROOM;
void create() {
	set( "short", "$RED$閻匕影螫魂$NOR$" );
	set( "object", ([
		"file10"   : "/open/magic-manor/obj/dark-soul-dagger",
		"amount7"  : 1,
		"file9"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount10" : 1,
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file7"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount4"  : 1,
	]) );
	set( "build", 12463 );
	set( "owner", "cowboy" );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room686",
		"west"      : "/open/clan/ou-cloud-club/room/room698",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

$RED$閻匕影螫魂閻匕影螫魂閻匕影螫魂閻匕影螫魂$NOR$
$RED$閻匕影螫魂閻匕影螫魂閻匕影螫魂閻匕影螫魂$NOR$
$RED$閻匕影螫魂閻匕影螫魂閻匕影螫魂閻匕影螫魂$NOR$
$RED$閻匕影螫魂閻匕影螫魂閻匕影螫魂閻匕影螫魂$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
