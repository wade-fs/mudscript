inherit ROOM;
void create() {
	set( "short", "$HIR$女生$HIM$廁所$NOR$" );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room37",
		"snake"     : "/open/clan/time-limit/room/room35",
	]) );
	set( "long", @LONG
這是所特別的廁所,一般不會有人來這裡上廁所,因為有愛哭鬼麥朵在這邊,
只要有人在這裡,麥朵就會纏著她並不斷抱怨,還會把水潑得到處都是,
令人難以忍受,麥朵這又在發脾氣,把一本日記丟向你,你機警一閃,
瞥見水龍頭底下有個蛇的圖案,似乎是有人特別刻上去的

LONG);
	setup();
	replace_program(ROOM);
}
