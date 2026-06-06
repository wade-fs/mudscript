inherit ROOM;
void create() {
	set( "short", "$MAG$$HBWHT$冥魔披風$NOR$" );
	set( "object", ([
		"file1"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount4"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount2"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-cloak",
	]) );
	set( "build", 10620 );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room17",
		"west"      : "/open/clan/time-limit/room/room166.c",
	]) );
	set( "long", @LONG
    =========================================================
      || \______________________________________________________/||
      ||                                                         ||
      ||                      冥魔披風                           ||
      ||  _____________________________________________________  ||
      ||/                                                      \ ||
        =========================================================

LONG);
	setup();
	replace_program(ROOM);
}
