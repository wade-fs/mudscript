inherit ROOM;
void create() {
	set( "short", "芙蓉宴廳" );
	set( "owner", "mill" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room613",
	]) );
	set( "long", @LONG
進門繞過一道淡綠綢屏風，迎面牆上掛著一副『芙蓉出水』圖，工筆彩
繪，狀極清雅，氣質卓絕。廳內陳列奢華，正中央一張雕花楠木青漆嵌玉大
圓桌，四周十二張鑲銀象牙扶手紅木椅，杯碗勺箸，入眼生輝。
    這裏便是醉仙樓的玫瑰廳，桌上平鋪著一份菜單(menu)。
LONG);
	setup();
	replace_program(ROOM);
}
