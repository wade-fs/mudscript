inherit ROOM;
void create() {
	set( "short", "正殿大廳" );
	set( "owner", "roariv" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room621.c",
		"north"     : "/open/clan/13_luck/room/room620",
		"out"       : "/open/clan/13_luck/room/room625",
		"east"      : "/open/clan/13_luck/room/room623.c",
		"west"      : "/open/clan/13_luck/room/room622.c",
	]) );
	set( "long", @LONG

    詩劍山莊的大廳，怖置的富貴萬千，顯示出詩劍山莊富可敵國的權
威，四面階有莊內門徒提的詩與畫的山水圖，讓你心中不免深覺不愧是
武林第一書香名門，詩劍山莊的人大都文武雙全，每人皆能提一手好詩
與畫一幅動人的美畫，往前就能見到名動天下的武林宗師，讓你心中悸
動不已，想一睹武林最年輕的一代宗師的尊顏‧

LONG);
	setup();
	replace_program(ROOM);
}
