inherit ROOM;
void create() {
	set( "short", "$MAG$$HBWHT$冥魔腰帶$NOR$" );
	set( "object", ([
		"file1"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount4"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount2"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-belt",
	]) );
	set( "build", 10116 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room169",
		"east"      : "/open/clan/time-limit/room/room174.c",
		"west"      : "/open/clan/time-limit/room/room176.c",
	]) );
	set( "long", @LONG
    =========================================================
      || \______________________________________________________/||
      ||                                                         ||
      ||                      冥魔腰帶                           ||
      ||  _____________________________________________________  ||
      ||/                                                      \ ||
        =========================================================

LONG);
	setup();
	replace_program(ROOM);
}
