inherit ROOM;
void create() {
	set( "short", "中央走道" );
	set( "owner", "roariv" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room632.c",
		"north"     : "/open/clan/13_luck/room/room630",
	]) );
	set( "long", @LONG

    詩劍山莊的中央走道乾淨典雅，兩旁種植著淡雅的黃色不知名的小
花，隨風輕送著，讓你不知覺的輕鬆了許多，左右兩旁傳來水流聲，想
必定有水池在兩旁，往上走聽到有許多人練武的聲音，應該不遠處就能
見到詩劍弟子在練武的情形吧‧

LONG);
	setup();
	replace_program(ROOM);
}
