inherit ROOM;
void create() {
	set( "short", "霧之林" );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room169",
		"east"      : "/open/clan/13_luck/room/room166.c",
		"west"      : "/open/clan/13_luck/room/room168.c",
		"north"     : "/open/clan/13_luck/room/room169",
	]) );
	set( "long", @LONG

　　謎樣般的森林，終年濃霧不散，眼前只見白茫茫的一大片，伸手
不見五指。越往裡頭走去，霧氣更是濃厚，西方似乎有一個陰暗、矮
小的洞穴，裡面傳出稀稀嗦嗦的聲音，似乎有一些生物在裡面走動的
樣子，但聽不出是啥東西。

LONG);
	setup();
	replace_program(ROOM);
}
