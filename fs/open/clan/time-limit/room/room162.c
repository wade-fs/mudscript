inherit ROOM;
void create() {
	set( "short", "金字塔入口" );
	set( "exits", ([
		"out"       : "/open/clan/time-limit/room/room163",
		"月"        : "/open/clan/time-limit/room/room114.c",
		"日"        : "/open/clan/time-limit/room/room161.c",
		"星"        : "/open/clan/time-limit/room/room301",
	]) );
	set( "long", @LONG
此地為金字塔的入口,高聳的岩壁讓人嘆為觀止,這世上竟有如此壯觀的地方,門口座落三座
獅身人面像,眼睛一直盯著自己看,好像在告訴你,絕不容許你冒犯在此沉睡的靈魂,不禁讓
人冷汗直流,獅身人面像底部有三個門,門上有隻手像是跟你討東西一樣,看來得要奉獻某些
寶物才能把門打開了,一旁有塊石板,上頭刻著

奉獻火龍之鱗可通往日    奉獻青蛇護符可通往月    奉獻妖幻之心可通往星

LONG);
	setup();
	replace_program(ROOM);
}
