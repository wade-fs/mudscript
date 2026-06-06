inherit ROOM;
void create() {
	set( "short", "$MAG$$HBWHT$冥魔羽靴$NOR$" );
	set( "build", 10599 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room166",
		"south"     : "/open/clan/time-limit/room/room168",
	]) );
	set( "long", @LONG
    =========================================================
      || \______________________________________________________/||
      ||                                                         ||
      ||                      冥魔羽靴                           ||
      ||  _____________________________________________________  ||
      ||/                                                      \ ||
        =========================================================

LONG);
	setup();
	replace_program(ROOM);
}
