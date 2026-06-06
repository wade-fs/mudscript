inherit ROOM;
void create() {
	set( "short", "霧之林" );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room163.c",
		"south"     : "/open/clan/13_luck/room/room166",
		"west"      : "/open/clan/13_luck/room/room166",
		"north"     : "/open/clan/13_luck/room/room169.c",
	]) );
	set( "long", @LONG

　　謎樣般的森林，終年濃霧不散，眼前只見白茫茫的一大片，伸手
不見五指。越往裡頭走去，霧氣更是濃厚，突然一股股的寒風不時由
四方吹來，令人打了個冷顫。不遠處的草堆裡，不時傳來稀稀嗦嗦的
聲音，看樣子似乎有什麼東西躲在那。

LONG);
	setup();
	replace_program(ROOM);
}
