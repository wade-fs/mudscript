inherit ROOM;
void create() {
	set( "short", "東廂客房" );
	set( "owner", "roarii" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room572",
	]) );
	set( "long", @LONG
這是用來招待遠客住宿的客房，雖然易水樓的訪客不多，不過
還是有前來討教或是來鑽研武學更高深境界的各宗師。這裡看起來
乾乾淨靜的，簡單淡雅，東邊開了個窗戶，和栩的陽光照射進來，
十分舒服。
LONG);
	setup();
	replace_program(ROOM);
}
