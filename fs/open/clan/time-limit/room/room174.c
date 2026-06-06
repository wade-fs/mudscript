inherit ROOM;
void create() {
	set( "short", "$MAG$$HBWHT$冥魔邪盾$NOR$" );
	set( "build", 10168 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room17",
		"east"      : "/open/clan/time-limit/room/room173.c",
		"west"      : "/open/clan/time-limit/room/room175.c",
	]) );
	set( "long", @LONG
    =========================================================
      || \______________________________________________________/||
      ||                                                         ||
      ||                      冥魔邪盾                           ||
      ||  _____________________________________________________  ||
      ||/                                                      \ ||
        =========================================================

LONG);
	setup();
	replace_program(ROOM);
}
