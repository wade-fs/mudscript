inherit ROOM;
void create() {
	set( "short", "曾經滄海樓" );
	set( "build", 16803 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room243.c",
		"south"     : "/open/clan/13_luck/room/room245.c",
	]) );
	set( "long", @LONG

    曾經滄海難為水，除卻巫山不是雲，不管新進還是已不玩的幫眾
，感謝你對十三的支持，吉祥才會有今天的壯大，此樓為紀念曾經入
過十三卻沒機會在玩的幫眾門，沒有你們以前的貢獻，也沒有今天的
十三，雖然你以退隱江湖了，但還是感謝你。

LONG);
	setup();
	replace_program(ROOM);
}
