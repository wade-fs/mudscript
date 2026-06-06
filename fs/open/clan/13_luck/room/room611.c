inherit ROOM;
void create() {
	set( "short", "牡丹宴廳" );
	set( "owner", "mill" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room613",
	]) );
	set( "long", @LONG
進門繞過一道淡紅綢屏風，迎面牆上掛著一副『牡丹爭艷』圖，牡丹是
中國國花，素以富貴著稱。圖側對聯: 幽徑天姿呈獨秀，古園國色冠群芳。
襯託了那一莖牡丹分外精神。廳內陳列奢華，正中央一張雕花楠木青漆嵌玉
大圓桌，四周十二張鑲銀象牙扶手紅木椅，杯碗勺箸，入眼生輝。
    這裏便是醉仙樓的玫瑰廳，桌上平鋪著一份菜單(menu)。
LONG);
	setup();
	replace_program(ROOM);
}
