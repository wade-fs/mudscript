inherit ROOM;
void create() {
	set( "short", "七龍精元房" );
	set( "object", ([
		"amount4"  : 3826,
		"amount7"  : 602,
		"file7"    : "/open/fire-hole/obj/k-pill",
		"file6"    : "/open/fire-hole/obj/w-pill",
		"file1"    : "/open/fire-hole/obj/g-pill",
		"file8"    : "/open/gblade/obj/paper",
		"amount8"  : 1,
		"amount6"  : 2403,
		"file5"    : "/open/fire-hole/obj/p-pill",
		"file4"    : "/open/fire-hole/obj/r-pill",
		"amount2"  : 1166,
		"amount5"  : 967,
		"amount3"  : 728,
		"amount1"  : 3252,
		"file3"    : "/open/fire-hole/obj/y-pill",
		"file2"    : "/open/fire-hole/obj/b-pill",
	]) );
	set( "build", 10299 );
	set( "owner", "mika" );
	set( "exits", ([
		"west"      : "/open/clan/dark-forest/room/room36",
	]) );
	set( "long", @LONG
一號右邊一號右邊一號右邊一號右邊一號右邊
一號右邊一號右邊一號右邊一號右邊一號右邊
一號右邊一號右邊一號右邊一號右邊一號右邊
一號右邊一號右邊一號右邊一號右邊一號右邊
一號右邊一號右邊一號右邊一號右邊一號右邊
一號右邊一號右邊一號右邊一號右邊一號右邊
一號右邊一號右邊一號右邊一號右邊一號右邊
LONG);
	setup();
	replace_program(ROOM);
}
