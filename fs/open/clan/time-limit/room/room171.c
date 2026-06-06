inherit ROOM;
void create() {
	set( "short", "$MAG$$HBWHT$冥魔脛甲$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-leggings",
	]) );
	set( "build", 10104 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room170",
		"south"     : "/open/clan/time-limit/room/room172",
	]) );
	set( "long", @LONG
    =========================================================
      || \______________________________________________________/||
      ||                                                         ||
      ||                      冥魔脛甲                           ||
      ||  _____________________________________________________  ||
      ||/                                                      \ ||
        =========================================================

LONG);
	setup();
	replace_program(ROOM);
}
