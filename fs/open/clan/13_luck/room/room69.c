inherit ROOM;
void create() {
	set( "short", "武器室" );
	set( "owner", "son" );
	set( "object", ([
		"file5"    : "/obj/gift/xiandan",
		"file3"    : "/obj/gift/hobowdan",
		"file6"    : "/obj/gift/xiandan",
		"file7"    : "/obj/gift/xiandan",
		"file1"    : "/obj/gift/shenliwan",
		"amount9"  : 1,
		"amount1"  : 1,
		"file2"    : "/obj/gift/shenliwan",
		"amount7"  : 1,
		"amount8"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"file9"    : "/obj/gift/shenliwan",
		"amount2"  : 1,
		"file10"   : "/obj/gift/shenliwan",
		"amount10" : 1,
		"amount6"  : 1,
		"file8"    : "/obj/gift/shenliwan",
	]) );
	set( "build", 10026 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room67",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    妳隨心所欲的往武器室走來，此處乃是小南平日常用的空手武器
妳不由自主的想去摸摸看這些武器，當妳靠近這些武器時，突然覺的
四週的迷霧由水藍轉變為炙紅，團團的圍繞著妳，強大的壓迫感迫使
妳不得不退後，此時妳才發現原來這些武器是有靈性的．

 
妳覺得炙紅的迷霧正圍繞在妳四周


LONG);
	setup();
	replace_program(ROOM);
}
