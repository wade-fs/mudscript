inherit ROOM;
void create() {
	set( "short", "古式涼亭" );
	set( "owner", "mill" );
	set( "object", ([
		"file3"    : "/open/fire-hole/obj/g-pill",
		"amount3"  : 45,
		"file1"    : "/open/fire-hole/obj/r-pill",
		"file2"    : "/open/mogi/castle/obj/sspill",
		"amount2"  : 3,
		"amount1"  : 70,
	]) );
	set( "build", 10009 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room425.c",
		"south"     : "/open/clan/13_luck/room/room403",
	]) );
	set( "long", @LONG

　　踏著輕鬆的步閥、懷著愉悅的心情，你來到了一處造景相當講究的
一座涼亭，亭中還擺著幾張桌椅供人歇歇腳。你發現這裡的桌椅都十分
的乾淨，似乎有人常來清理。陣陣蘭花的香氣，隨著清風飄來，令人感
覺神清氣爽，在這裡你感到心情格外的輕鬆、愉快。 

LONG);
	setup();
	replace_program(ROOM);
}
