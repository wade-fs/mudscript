inherit ROOM;
void create() {
	set( "short", "刀類武器房" );
	set( "object", ([
		"file1"    : "/open/capital/obj/4-3",
		"amount3"  : 1,
		"amount1"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file2"    : "/open/capital/obj/4-3",
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file5"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file6"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount4"  : 1,
	]) );
	set( "build", 10386 );
	set( "owner", "mika" );
	set( "exits", ([
		"east"      : "/open/clan/dark-forest/room/room35",
	]) );
	set( "long", @LONG
二號左邊二號左邊二號左邊二號左邊二號左邊
二號左邊二號左邊二號左邊二號左邊二號左邊
二號左邊二號左邊二號左邊二號左邊二號左邊
二號左邊二號左邊二號左邊二號左邊二號左邊
二號左邊二號左邊二號左邊二號左邊二號左邊
二號左邊二號左邊二號左邊二號左邊二號左邊
二號左邊二號左邊二號左邊二號左邊二號左邊
LONG);
	setup();
	replace_program(ROOM);
}
