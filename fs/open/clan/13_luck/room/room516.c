inherit ROOM;
void create() {
	set( "short", "西長廊" );
	set( "build", 10581 );
	set( "owner", "fireer" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room515",
		"south"     : "/open/clan/13_luck/room/room517",
	]) );
	set( "long", @LONG
你現在正在西長廊上，橡木所鋪的地板，感覺起來一塵不染。陽光
由窗上灑落了下來，使得長廊特別的明亮。兩旁還掛了許多的字畫，全
是名家手筆，還真令你想細細琢摹。不忍離去呢。跟四周的強烈殺氣成
了一個強烈的對比，仿佛來到了帶著天堂的環境，但是是地獄的地方。

LONG);
	setup();
	replace_program(ROOM);
}
