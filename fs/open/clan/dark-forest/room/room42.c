inherit ROOM;
void create() {
	set( "short", "補藥房" );
	set( "object", ([
		"file4"    : "/open/ping/obj/poison_pill",
		"amount2"  : 881,
		"amount5"  : 8731,
		"file5"    : "/open/killer/obj/atman_pill",
		"amount4"  : 289,
		"amount3"  : 991,
		"amount1"  : 736,
		"file3"    : "/open/mon/obj/mon-pill",
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"file1"    : "/open/mogi/castle/obj/sspill",
	]) );
	set( "build", 10035 );
	set( "owner", "mika" );
	set( "exits", ([
		"west"      : "/open/clan/dark-forest/room/room41",
	]) );
	set( "long", @LONG
三號右邊三號右邊三號右邊三號右邊三號右邊
    三號右邊三號右邊三號右邊三號右邊三號右邊
    三號右邊三號右邊三號右邊三號右邊三號右邊
    三號右邊三號右邊三號右邊三號右邊三號右邊
    三號右邊三號右邊三號右邊三號右邊三號右邊
    三號右邊三號右邊三號右邊三號右邊三號右邊
    三號右邊三號右邊三號右邊三號右邊三號右邊
LONG);
	setup();
	replace_program(ROOM);
}
