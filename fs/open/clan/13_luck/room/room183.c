inherit ROOM;
void create() {
	set( "short", "盤龍小徑" );
	set( "owner", "mill" );
	set( "build", 10561 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room369.c",
		"out"       : "/open/clan/13_luck/room/room534.c",
		"south"     : "/open/clan/13_luck/room/room151",
	]) );
	set( "long", @LONG

    在這盤龍小徑的兩旁全是些高大壯碩的松樹，一遍綠蔭盎然。樹
下的淡雅黃色不知名的小花，隨風輕送著。天空中白雲隨著風四處飄
逸，清風拂面吹來，讓人覺的十分的舒適，感覺十分的愜意。在前面
不遠處，有一座古式涼亭，供人休息用。

LONG);
	setup();
	replace_program(ROOM);
}
