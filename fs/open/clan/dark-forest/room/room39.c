inherit ROOM;
void create() {
	set( "short", "劍類武器房" );
	set( "object", ([
		"amount5"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/capital/obj/4-4",
		"amount4"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/capital/obj/4-4",
		"amount1"  : 1,
		"file3"    : "/open/gsword/obj1/blosword",
		"amount2"  : 1,
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
	]) );
	set( "build", 10033 );
	set( "owner", "mika" );
	set( "exits", ([
		"west"      : "/open/clan/dark-forest/room/room35",
	]) );
	set( "long", @LONG
二號右邊二號右邊二號右邊二號右邊二號右邊
二號右邊二號右邊二號右邊二號右邊二號右邊
二號右邊二號右邊二號右邊二號右邊二號右邊
二號右邊二號右邊二號右邊二號右邊二號右邊
二號右邊二號右邊二號右邊二號右邊二號右邊
二號右邊二號右邊二號右邊二號右邊二號右邊
二號右邊二號右邊二號右邊二號右邊二號右邊
LONG);
	setup();
	replace_program(ROOM);
}
