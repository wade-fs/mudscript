inherit ROOM;
void create() {
	set( "short", "烈焰峽谷" );
	set( "owner", "evonne" );
	set( "object", ([
		"amount5"  : 1,
		"file6"    : "/open/mogi/castle/obj/seven6-dark-head",
		"amount4"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/mogi/castle/obj/seven4-dark-head",
		"file5"    : "/open/mogi/castle/obj/seven7-dark-head",
		"amount6"  : 1,
		"file3"    : "/open/mogi/castle/obj/seven3-dark-head",
	]) );
	set( "build", 10010 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room653",
		"east"      : "/open/clan/13_luck/room/room593",
	]) );
	set( "long", @LONG
當你來到了烈焰峽谷，環繞在四周的熱氣早以讓你快要支撐不住了。而
谷內到處都有強烈的火燄在那然燒，好像永不熄滅似的，把整個大地都烤成
死寂一遍。而好像只有駐守在這的火焰魔法軍團能夠自在的停留在這。東邊
是風陵小徑，而且是是峽谷的延伸。

LONG);
	setup();
	replace_program(ROOM);
}
