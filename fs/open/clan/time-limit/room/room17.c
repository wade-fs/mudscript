inherit ROOM;
void create() {
	set( "short", "$MAG$$HBWHT$冥魔指套$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount4"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount2"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount7"  : 1,
	]) );
	set( "build", 10034 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room165",
		"east"      : "/open/clan/time-limit/room/room170.c",
		"west"      : "/open/clan/time-limit/room/room169.c",
		"south"     : "/open/clan/time-limit/room/room174.c",
	]) );
	set( "long", @LONG
    =========================================================
      || \______________________________________________________/||
      ||                                                         ||
      ||                      冥魔指套                           ||
      ||  _____________________________________________________  ||
      ||/                                                      \ ||
        =========================================================

LONG);
	setup();
	replace_program(ROOM);
}
