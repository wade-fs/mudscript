inherit ROOM;
void create() {
	set( "short", "火雁" );
	set( "owner", "cong" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room15",
		"south"     : "/open/clan/sky-wu-chi/room/room289.c",
	]) );
	set( "long", @LONG
步入這裡你發現了雪雁在這裡練功...他以他驚人的內力做出這個人間煉獄
這時你不經懷疑他的修為是否以達到天人...和幫主相比又會差多少ㄋ...
所以你決定一探究盡
突然你被他的刀氣所傷...完全沒有辦法進入他所防守的區域...只被他一昧攻擊
結果你輸了..他指說出一句話 怒 殺 斬 
LONG);
	setup();
	replace_program(ROOM);
}
