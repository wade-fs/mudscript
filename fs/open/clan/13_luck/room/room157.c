inherit ROOM;
void create() {
	set( "short", "霧之林" );
	set( "build", 37 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room157",
		"east"      : "/open/clan/13_luck/room/room157",
		"west"      : "/open/clan/13_luck/room/room157.c",
		"north"     : "/open/clan/13_luck/room/room158.c",
		"out"       : "/open/clan/13_luck/room/room152.c",
	]) );
	set( "long", @LONG

　　謎樣般的森林，終年濃霧不散，眼前只見白茫茫的一大片，伸手
不見五指。樹林內更是聽不到蟲鳴鳥叫，只覺在這濃濃白霧之中，充
滿著詭異的氣氛，似乎有什麼東西，正瞪大著雙眼，在遠處監視著你
的一舉一動，詭異的氣息壓的你喘不過氣來。

LONG);
	setup();
	replace_program(ROOM);
}
