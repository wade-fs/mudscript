inherit ROOM;
void create() {
	set( "short", "$MAG$$HBWHT$冥魔帝冠$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-helmet",
	]) );
	set( "build", 10814 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room171.c",
		"south"     : "/open/clan/time-limit/room/room173",
		"west"      : "/open/clan/time-limit/room/room17.c",
	]) );
	set( "long", @LONG
    =========================================================
      || \______________________________________________________/||
      ||                                                         ||
      ||                      冥魔帝冠                           ||
      ||  _____________________________________________________  ||
      ||/                                                      \ ||
        =========================================================

LONG);
	setup();
	replace_program(ROOM);
}
