inherit ROOM;
void create() {
	set( "short", "『山道』" );
	set( "owner", "poll" );
	set( "build", 10157 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room474",
		"south"     : "/open/clan/13_luck/room/room461",
	]) );
	set( "long", @LONG
  
     從剛剛的桃花林往東北邊走了過來，竟然會是一條蜿蜿蜒蜒的山道，而
 似乎在山頂上似乎有一座建築物，而聽說住在這裡的居民說，在山頂上面的
 人們都很好相處，對每個人都很友善，不論是下山採購民生用品或者是辦事
 情，他們的性情都是很熱情的。

LONG);
	setup();
	replace_program(ROOM);
}
