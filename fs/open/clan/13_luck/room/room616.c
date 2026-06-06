inherit ROOM;
void create() {
	set( "short", "楊州北門" );
	set( "owner", "mill" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room608",
		"south"     : "/open/clan/13_luck/room/room617",
	]) );
	set( "long", @LONG
這是北城門，因為曾經失火，到現在城牆還是黑乎乎的，因此白紙
黑字的官府告示(gaoshi)就顯得特別現眼。走在在一條繁忙的街道上，
看著操著南腔北調的人們行色匆匆，許多人都往南邊走去，那裏有一個
熱鬧的廣場。。北方是一片崇山峻嶺，一條黃土小徑在山裏蜿蜒而上。
LONG);
	setup();
	replace_program(ROOM);
}
