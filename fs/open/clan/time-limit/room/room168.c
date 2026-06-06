inherit ROOM;
void create() {
	set( "short", "$MAG$$HBWHT$冥魔甲胄$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount3"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-armor",
	]) );
	set( "build", 10124 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room169.c",
		"north"     : "/open/clan/time-limit/room/room167.c",
		"south"     : "/open/clan/time-limit/room/room176",
	]) );
	set( "long", @LONG
    =========================================================
      || \______________________________________________________/||
      ||                                                         ||
      ||                      冥魔甲胄                           ||
      ||  _____________________________________________________  ||
      ||/                                                      \ ||
        =========================================================

LONG);
	setup();
	replace_program(ROOM);
}
