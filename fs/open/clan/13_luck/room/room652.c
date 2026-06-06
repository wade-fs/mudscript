inherit ROOM;
void create() {
	set( "short", "烈焰峽谷" );
	set( "owner", "evonne" );
	set( "build", 10038 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room653",
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
