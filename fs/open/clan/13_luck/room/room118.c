inherit ROOM;
void create() {
	set( "short", "隔世橋" );
	set( "owner", "zeros" );
	set( "build", 10011 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room94",
		"enter"     : "/open/clan/13_luck/room/room119",
	]) );
	set( "long", @LONG
你漫步欣賞著這湖美麗的風光美景,發現在不遠處有一條連接至
湖中小島的橋,止時的你急著前往小島去一探究竟是否為一個隱
居的好地方,正當你靠近橋時發現橋口有一塊大石,石上寫著 不歡
迎外來客的拜訪,只歡迎要來止安度晚年的人,看到止你心中一慌
不知是否要就只隱居去.
LONG);
	setup();
	replace_program(ROOM);
}
