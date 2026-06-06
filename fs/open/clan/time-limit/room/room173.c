inherit ROOM;
void create() {
	set( "short", "$MAG$$HBWHT$冥魔指戒$NOR$" );
	set( "object", ([
		"file1"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount4"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount2"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-ring",
	]) );
	set( "build", 10256 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room170",
		"east"      : "/open/clan/time-limit/room/room172.c",
		"west"      : "/open/clan/time-limit/room/room174.c",
	]) );
	set( "long", @LONG
    =========================================================
      || \______________________________________________________/||
      ||                                                         ||
      ||                      冥魔指戒                           ||
      ||  _____________________________________________________  ||
      ||/                                                      \ ||
        =========================================================

LONG);
	setup();
	replace_program(ROOM);
}
