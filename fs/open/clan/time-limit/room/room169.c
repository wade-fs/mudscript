inherit ROOM;
void create() {
	set( "short", "$MAG$$HBWHT$冥魔寶墜$NOR$" );
	set( "build", 10025 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room166",
		"east"      : "/open/clan/time-limit/room/room17.c",
		"west"      : "/open/clan/time-limit/room/room168.c",
		"south"     : "/open/clan/time-limit/room/room175.c",
	]) );
	set( "long", @LONG
    =========================================================
      || \______________________________________________________/||
      ||                                                         ||
      ||                      冥魔寶墜                           ||
      ||  _____________________________________________________  ||
      ||/                                                      \ ||
        =========================================================

LONG);
	setup();
	replace_program(ROOM);
}
