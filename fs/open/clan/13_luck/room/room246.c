inherit ROOM;
void create() {
	set( "short", "齊家安幫樓" );
	set( "build", 10269 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room245.c",
		"south"     : "/open/clan/13_luck/room/room180.c",
	]) );
	set( "long", @LONG

    十三吉祥成立至今，幫務蒸蒸日上，也有賴幾位前人的努力幫住
幫派穩固，如天，殘心，廖官人，混口飯吃，可愛小豬頭等人，為幫
犧牲奉獻，為了感謝這些前人的努力，就把此樓命名為齊家安幫樓，
希望後人能跟他們學習並有過之而無不及。

LONG);
	setup();
	replace_program(ROOM);
}
