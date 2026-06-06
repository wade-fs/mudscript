inherit ROOM;
void create() {
	set( "short", "$MAG$$HBWHT$斷裂牙齒$NOR$" );
	set( "build", 10660 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room168",
		"east"      : "/open/clan/time-limit/room/room175.c",
		"out"       : "/open/clan/time-limit/room/room177",
	]) );
	set( "long", @LONG
    =========================================================
      || \______________________________________________________/||
      ||                                                         ||
      ||                      斷裂牙齒                           ||
      ||  _____________________________________________________  ||
      ||/                                                      \ ||
        =========================================================

LONG);
	setup();
	replace_program(ROOM);
}
