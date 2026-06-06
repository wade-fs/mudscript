inherit ROOM;
void create() {
	set( "short", "$MAG$$HBWHT$冥魔足環$NOR$" );
	set( "build", 10220 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room171",
		"west"      : "/open/clan/time-limit/room/room173.c",
	]) );
	set( "long", @LONG
    =========================================================
      || \______________________________________________________/||
      ||                                                         ||
      ||                      冥魔足環                           ||
      ||  _____________________________________________________  ||
      ||/                                                      \ ||
        =========================================================

LONG);
	setup();
	replace_program(ROOM);
}
