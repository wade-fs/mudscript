inherit ROOM;
void create() {
	set( "short", "$MAG$$HBWHT$冥魔肩甲$NOR$" );
	set( "build", 10104 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room165.c",
		"south"     : "/open/clan/time-limit/room/room169",
		"west"      : "/open/clan/time-limit/room/room167.c",
	]) );
	set( "long", @LONG
    =========================================================
      || \______________________________________________________/||
      ||                                                         ||
      ||                      冥魔肩甲                           ||
      ||  _____________________________________________________  ||
      ||/                                                      \ ||
        =========================================================

LONG);
	setup();
	replace_program(ROOM);
}
