inherit ROOM;
void create() {
	set( "short", "ζ武器室ζ" );
	set( "exits", ([
		"east"      : "/open/clan/demon_castle/room/room18",
	]) );
	set( "build", 11520 );
	set( "owner", "son" );
	set( "object", ([
		"amount10" : 1,
		"file5"    : "/open/mon/obj/ghost-claw",
		"amount8"  : 1,
		"amount9"  : 1,
		"amount1"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount7"  : 1,
		"file8"    : "/open/mon/obj/ghost-claw",
		"amount4"  : 1,
		"file3"    : "/open/mon/obj/ghost-claw",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file10"   : "/open/mon/obj/ghost-claw",
		"amount3"  : 1,
		"file7"    : "/open/mon/obj/ghost-claw",
		"file4"    : "/open/mon/obj/ghost-claw",
		"file9"    : "/open/mon/obj/ghost-claw",
		"amount2"  : 1,
		"file1"    : "/open/mon/obj/ghost-claw",
	]) );
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
