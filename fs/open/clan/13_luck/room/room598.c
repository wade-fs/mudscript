inherit ROOM;
void create() {
	set( "short", "堂內走道" );
	set( "owner", "roarii" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room599.c",
		"south"     : "/open/clan/13_luck/room/room597",
	]) );
	set( "long", @LONG
不知道為什麼你走在這一條走道上，老是覺得有一股寒
風從你的背後貫穿你的後背，使你打了一個寒噤。昏昏暗暗
的走道上，令人有一股昏眩的感受，兩旁石壁上的所雕刻的
石龍。彷彿要把你從他的口中吞食下去！令你十分的難受。

LONG);
	setup();
	replace_program(ROOM);
}
