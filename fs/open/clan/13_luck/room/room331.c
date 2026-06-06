inherit ROOM;
void create() {
	set( "short", "小浪女居" );
	set( "owner", "smalloo" );
	set( "object", ([
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"file2"    : "/open/poison/obj/box_book",
		"amount7"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/poison/obj/pbasebook",
		"amount5"  : 1,
		"amount6"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10587 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room332",
	]) );
	set( "long", @LONG

    據說小浪女打敗聶風後，這風字居就歸小浪女所有，而聶風則
位居外面的神風堂，但小浪女覺的這風字跟他在合不過，因為她叫
風魔小浪女，所以，想要入侵風字居或整個神風堂，不怕聶風，也
要想到還有一個風字居的主人，風魔小浪女。 


LONG);
	setup();
	replace_program(ROOM);
}
