inherit ROOM;
void create() {
	set( "short", "漢水南岸" );
	set( "owner", "poll" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room605",
		"south"     : "/open/clan/13_luck/room/room607",
	]) );
	set( "long", @LONG
面前是一條波濤翻滾的大江(river) 。濁流滾滾，萬舟競發
。兩岸渡船來來往往，江邊一長溜擺滿了魚攤，漁家就將船泊在
岸邊，幾個破蘿支一塊木板，板上擺滿了活蹦亂跳的漢江鯉魚。
過去不遠，是有名的老河口，不少過江客都在這裏等待渡船擺渡
。
LONG);
	setup();
	replace_program(ROOM);
}
