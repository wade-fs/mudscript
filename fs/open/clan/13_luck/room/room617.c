inherit ROOM;
void create() {
	set( "short", "北大街" );
	set( "owner", "mill" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room616.c",
		"south"     : "/open/clan/13_luck/room/room618",
		"east"      : "/open/clan/13_luck/room/room615.c",
		"west"      : "/open/clan/13_luck/room/room609",
	]) );
	set( "long", @LONG
這是一條寬闊的青石街道，向南北兩頭延伸。北邊是北城門通向城外
。南邊顯得很繁忙。東邊是一座兩層的樓閣，掛著“太白遺風”的招簾，
門額上懸掛一方橫匾，“醉仙樓”三字擦得閃閃發亮，乃是蘇學士的手筆
。陣陣酒肉香酒香讓你垂涎欲滴。西邊是一座古樸的廟宇，香火繚繞，那
就是天下學武之人所共同敬仰的武廟了。
LONG);
	setup();
	replace_program(ROOM);
}
