inherit ROOM;
void create() {
	set( "short", "玫瑰宴廳" );
	set( "owner", "poll" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room613",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
進門繞過一道淡黃綢屏風，迎面牆上掛著一副『玫瑰含露』圖，鮮嫩欲
滴，花瓣輕分，似有香氣盈室。廳內陳列奢華，正中央一張雕花楠木青漆嵌
玉大圓桌，四周十二張鑲銀象牙扶手紅木椅，杯碗勺箸，入眼生輝。
    這裏便是醉仙樓的玫瑰廳，桌上平鋪著一份菜單(menu)。
LONG);
	setup();
	replace_program(ROOM);
}
