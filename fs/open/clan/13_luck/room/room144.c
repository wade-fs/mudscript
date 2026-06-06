inherit ROOM;
void create() {
	set( "short", "煉丹房" );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room137",
		"east"      : "/open/clan/13_luck/room/room359.c",
		"south"     : "/open/clan/13_luck/room/room358.c",
		"north"     : "/open/clan/13_luck/room/room357.c",
	]) );
	set( "build", 10086 );
	set( "long", @LONG

　　推開大門進來這裡，即看見一個大鼎放在正中央，定神一看此鼎
正是千金萬國鼎，相傳這是古代天子國師遺留下來的鼎，聽說可以煉
出長生不老丹跟返老還童丹。兩旁的弟子則專心注意鼎內的變化，深
怕一個不小心，煉製已久的丹藥就此毀壞。 

LONG);
	setup();
	replace_program(ROOM);
}
