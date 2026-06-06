inherit ROOM;
void create() {
	set( "short", "前堂" );
	set( "owner", "roarii" );
	set( "build", 10291 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room579",
		"north"     : "/open/clan/13_luck/room/room577",
	]) );
	set( "long", @LONG
這裡便是易水樓的前堂了，雖然在裝飾上不像宮殿般的華麗，
不過也稱得上是奢華了。一想到自己即將走進在武林如霧縹緲般傳
說的神秘地帶，心裡就不由得的打了個冷顫。有個神態瀟灑的公子
站在前方，而往樓上便是前廳了。
LONG);
	setup();
	replace_program(ROOM);
}
