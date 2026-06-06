inherit ROOM;
void create() {
	set( "short", "盤龍小徑" );
	set( "owner", "mill" );
	set( "object", ([
		"file1"    : "/open/mogi/castle/obj/black-ghost-head",
		"file2"    : "/open/mogi/castle/obj/white-ghost-head",
		"amount2"  : 1,
		"amount1"  : 1,
	]) );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room424.c",
		"south"     : "/open/clan/13_luck/room/room369.c",
	]) );
	set( "light_up", 1 );
	set( "build", 10084 );
	set( "long", @LONG

　　小徑的兩旁全是些高大壯碩的松樹，一遍綠蔭盎然。樹下的淡雅
黃色不知名的小花，隨風輕送著。在往前去便是古式涼亭，右邊是一
座蘭花園，一陣風吹來遠遠的也可以聞到蘭花的那股獨特芳香，總是
讓人舒服的不想離開，旁邊是一座水池，造景相當講究。

LONG);
	setup();
	replace_program(ROOM);
}
