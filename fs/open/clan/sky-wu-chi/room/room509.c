inherit ROOM;
void create() {
	set( "short", "迷霧森林" );
	set( "build", 6433 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room508",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG
一陣光影散去之後 只見到前方一道寬過千尺的瀑布 彷彿永無止境的
奔騰墜落 晶瑩的水珠如明珠一般飛濺而起 將四周籠罩在一片
白茫茫的濃霧濕氣之中 往旁邊望去 有一間小小的木屋
讓你不自覺的想往前走去 進去裡面看個究竟
LONG);
	setup();
	replace_program(ROOM);
}
