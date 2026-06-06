inherit ROOM;
void create() {
	set( "short", "月一樓梯" );
	set( "exits", ([
		"up"        : "/open/clan/time-limit/room/room108",
		"north"     : "/open/clan/time-limit/room/room110",
	]) );
	set( "long", @LONG
此地只有一把沙所做成的梯子,你不禁懷疑這個沙梯怎麼能承受你的重量,不過也沒有其他路
可以走了,只有試試看了,一踏上去發現沙梯雖然可以支撐自己的重量,但是底部卻慢慢在流
失當中,可能當初就是設計讓人只能往上爬而不能回頭吧,一想到這裡,對於前方路途的坎坷
已不在話下,眼看沙子已經快流到腳底,只好奮力向上爬

LONG);
	setup();
	replace_program(ROOM);
}
