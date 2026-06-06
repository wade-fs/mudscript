inherit ROOM;
void create() {
	set( "short", "又小又軟的視聽室" );
	set( "object", ([
		"amount6"  : 12,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount5"  : 45,
		"file5"    : "/open/doctor/pill/human_pill",
		"file6"    : "/open/fire-hole/obj/y-pill",
		"file4"    : "/open/fire-hole/obj/r-pill",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount4"  : 10,
		"amount3"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 11327 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room8",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
這裡是又小又軟每天奮鬥完唯一可以好好休息的地方，雖然裡面的陳設簡單，
可是該有的東西一項也不少。除了柔軟的沙發和高級的視聽設備，更有著幫主-小敏
的大幅照片掛在牆上，因為他總是逼又小又軟去做一些高難度的工作，又不給他
加班費，所以當他忙完回來後對著小敏的照片PK一小時是他生活的唯一寄托了
，一想到這裡，你不禁對又小又軟悲慘的遭遇感到十分的同情了。

LONG);
	setup();
	replace_program(ROOM);
}
