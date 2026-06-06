inherit ROOM;
void create() {
	set( "short", "白雪公主的房間" );
	set( "owner", "panhermes" );
	set( "build", 13173 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room382",
		"north"     : "/open/clan/sky-wu-chi/room/room384",
	]) );
	set( "long", @LONG
你正在白雪公主的房間，一片粉紅色的景像讓你在不知不覺中也變的溫柔起來，
就連太陽也都照射出粉紅色的光芒。一個雕刻精美的粉紅色衣櫃倚靠著牆邊而立
，牆上還有一個像門一般大小的鏡子，地上則排列了數十雙粉紅色的鞋子。你好
奇地想看衣櫃到底擺了什麼東西。
一個身穿雪白的僕人/servant/正在這兒整理打掃。
LONG);
	setup();
	replace_program(ROOM);
}
