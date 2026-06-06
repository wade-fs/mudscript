inherit ROOM;
void create() {
	set( "short", "其他武器房" );
	set( "object", ([
		"amount5"  : 1,
		"file1"    : "/open/capital/obj/icer",
		"amount3"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"file5"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file7"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount6"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount4"  : 1,
		"amount8"  : 1,
		"file2"    : "/open/capital/obj/icer",
		"amount7"  : 1,
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount1"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/magic-manor/obj/lin-cloud-fan",
	]) );
	set( "build", 10048 );
	set( "owner", "mika" );
	set( "exits", ([
		"east"      : "/open/clan/dark-forest/room/room44",
	]) );
	set( "long", @LONG
四號左邊四號左邊四號左邊四號左邊四號左邊
    四號左邊四號左邊四號左邊四號左邊四號左邊
    四號左邊四號左邊四號左邊四號左邊四號左邊
    四號左邊四號左邊四號左邊四號左邊四號左邊
    四號左邊四號左邊四號左邊四號左邊四號左邊
    四號左邊四號左邊四號左邊四號左邊四號左邊
    四號左邊四號左邊四號左邊四號左邊四號左邊
LONG);
	setup();
	replace_program(ROOM);
}
