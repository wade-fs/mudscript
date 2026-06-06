inherit ROOM;
void create() {
	set( "short", "醉仙居" );
	set( "owner", "mill" );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room404",
	]) );
	set( "build", 10006 );
	set( "light_up", 1 );
	set( "long", @LONG

    這裡就是星月堂裡，星月堂主專屬的==醉仙居==，一進入到醉仙
居裡，就看到大廳正中央的牆上掛著一幅好大的醉八仙圖，醉仙居名
產　【　清　溪　流　泉　】　名動天下，不是任何人都有機會品嚐
到的。這裡也是星月堂主忙裡偷閒的唯一地方。
LONG);
	setup();
	replace_program(ROOM);
}
