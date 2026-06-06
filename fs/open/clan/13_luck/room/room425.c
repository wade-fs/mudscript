inherit ROOM;
void create() {
	set( "short", "醉仙小道" );
	set( "object", ([
		"amount2"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"file4"    : "/open/mogi/castle/obj/seven6-dark-head",
		"file1"    : "/open/mogi/castle/obj/seven3-dark-head",
		"amount1"  : 1,
		"file3"    : "/open/mogi/castle/obj/seven7-dark-head",
		"file6"    : "/open/mogi/castle/obj/white-ghost-head",
		"amount4"  : 1,
		"file2"    : "/open/mogi/castle/obj/seven5-dark-head",
		"file5"    : "/open/mogi/castle/obj/black-ghost-head",
	]) );
	set( "owner", "mill" );
	set( "build", 10006 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room151",
		"south"     : "/open/clan/13_luck/room/room404",
	]) );
	set( "long", @LONG

　　現在你位於醉仙居的長廊上，兩旁的假山假水十分地美麗，花園
之中百花盛開互相爭奇鬥豔。這些花全部都是星月堂主所親手栽培的
！在往前去便是星月堂裡的醉仙居，陣陣的酒香撲鼻而來，看來星月
堂主正在裡面品嚐美酒。 

LONG);
	setup();
	replace_program(ROOM);
}
