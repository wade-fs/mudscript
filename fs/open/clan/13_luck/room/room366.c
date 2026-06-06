inherit ROOM;
void create() {
	set( "short", "龍爪崖" );
	set( "owner", "evonne" );
	set( "build", 10012 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room491.c",
		"north"     : "/open/clan/13_luck/room/room370.c",
	]) );
	set( "long", @LONG

    經由鳳凰山崖的通道中一個不起眼的洞口來到這，見此處山形如
龍爪張開，雄奇壯麗無比。這才想起原來這裡就是有名的『龍爪崖』
。向前望去，映入眼簾的是一處山水秀麗之地。左望群峰起伏，宛如
星羅橫佈、右近一峰，形如巨筆，氣勢軒昂。峰下流經的河道，如神
龍翻騰，此地不外乎是一處洞天福地。

LONG);
	setup();
	replace_program(ROOM);
}
