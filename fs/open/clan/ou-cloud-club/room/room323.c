inherit ROOM;
void create() {
	set( "short", "$HIW$miles大廳$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"amount8"  : 1,
		"file6"    : "/open/fire-hole/obj/p-pill",
		"amount6"  : 10,
		"file8"    : "/open/fire-hole/obj/y-pill",
		"amount7"  : 1,
		"file5"    : "/open/mogi/castle/obj/sspill",
		"amount4"  : 1,
		"file4"    : "/open/ping/obj/neck0",
		"amount2"  : 43,
		"file7"    : "/open/ping/obj/neck0",
		"amount3"  : 59,
		"amount9"  : 1,
		"file10"   : "/open/fire-hole/obj/b-pill",
		"amount5"  : 1,
		"amount10" : 35,
		"file1"    : "/open/gsword/obj1/bpball",
		"file2"    : "/open/fire-hole/obj/w-pill",
		"file3"    : "/open/fire-hole/obj/r-pill",
		"file9"    : "/obj/gift/xiandan",
	]) );
	set( "light_up", 1 );
	set( "build", 10806 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room401.c",
		"west"      : "/open/clan/ou-cloud-club/room/room384.c",
		"up"        : "/open/clan/ou-cloud-club/room/room315.c",
		"east"      : "/open/clan/ou-cloud-club/room/room383",
	]) );
	set( "long", @LONG
$$ $$ $$ $$ $$ $$ $$ $$ $$
$$ $$ $$ $$ $$ $$ $$ $$ $$
$$ $$ $$ $$ $$ $$ $$ $$ $$
$$ $$ $$ $$ $$ $$ $$ $$ $$
$$ $$ $$ $$ $$ $$ $$ $$ $$
$$ $$ $$ $$ $$ $$ $$ $$ $$
$$ $$ $$ $$ $$ $$ $$ $$ $$
$$ $$ $$ $$ $$ $$ $$ $$ $$
$$ $$ $$ $$ $$ $$ $$ $$ $$
$$ $$ $$ $$ $$ $$ $$ $$ $$
LONG);
	setup();
	replace_program(ROOM);
}
