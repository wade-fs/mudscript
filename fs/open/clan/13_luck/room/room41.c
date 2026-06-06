inherit ROOM;
void create() {
	set( "short", "客棧左廳" );
	set( "object", ([
		"file1"    : "/open/scholar/obj/icefan",
		"amount1"  : 1,
	]) );
	set( "build", 11378 );
	set( "exits", ([
		"鳳凰樓"    : "/open/clan/13_luck/room/room99",
		"east"      : "/open/clan/13_luck/room/room40.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    歡迎您來到十三吉祥的客棧左廳，請先向櫃檯的店小二CHECK IN
辦理好手續後，您就可以回到妳的廂房休息了，如有需要任何服務請
直撥CT頻道將有專人為您服務～～
                                               謝謝光臨 ！！

             
               從這往前走，即是『鳳凰樓』。
             
LONG);
	setup();
	replace_program(ROOM);
}
