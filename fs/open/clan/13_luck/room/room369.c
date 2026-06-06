inherit ROOM;
void create() {
	set( "short", "盤龍小徑" );
	set( "owner", "mill" );
	set( "build", 10557 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room155.c",
		"south"     : "/open/clan/13_luck/room/room183.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

　　小徑的兩旁全是些高大壯碩的松樹，一遍綠蔭盎然。樹下鳥語花
香長滿著許多的花朵，四周傳來陣陣花香，不知名的鳥兒在為你輕聲
歌唱，尤如是一座鳥語花香的世外桃園。一路上清風拂面吹來，聽著
鳥兒歌唱，一路上心情十分愉快。

LONG);
	setup();
	replace_program(ROOM);
}
