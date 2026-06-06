inherit ROOM;
void create() {
	set( "short", "金行三" );
	set( "object", ([
		"amount4"  : 1,
		"amount9"  : 1,
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"file1"    : "/obj/gift/xiandan",
		"file8"    : "/obj/gift/xisuidan",
		"amount1"  : 1,
		"amount5"  : 1,
		"file7"    : "/obj/stone/powder",
		"amount2"  : 1,
		"amount6"  : 1,
		"file10"   : "/obj/stone/suipian",
		"amount7"  : 116,
		"file6"    : "/obj/gift/unknowdan",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount10" : 14,
		"file5"    : "/obj/gift/shenliwan",
		"file9"    : "/obj/gift/bingtang",
		"file2"    : "/obj/gift/xiandan",
	]) );
	set( "build", 10121 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room644",
	]) );
	set( "long", @LONG
不想寫了啦.......................................> < 
不想寫了啦.......................................> < 
不想寫了啦.......................................> < 
不想寫了啦.......................................> < 
LONG);
	setup();
	replace_program(ROOM);
}
