inherit ROOM;
void create() {
	set( "short", "黑洞" );
	set( "owner", "sevenll" );
	set( "build", 100 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room675",
	]) );
	set( "long", @LONG
    你往前走一步,只覺得前面有一股吸力把你吸住,你無法離
開,只能隨著吸力任其扭轉你的身體,過了許久你總算停了下來
,在你眼前的只有黑暗而已!!你腦中閃過一個念頭,你是否還活
著,四周都碰觸不到任何東西,漸漸地你的恐懼佔有了你的身體
,你失去了所有知覺暈了過去.

LONG);
	setup();
	replace_program(ROOM);
}
