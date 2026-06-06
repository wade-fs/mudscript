inherit ROOM;
void create() {
	set( "short", "金行四" );
	set( "object", ([
		"amount2"  : 1,
		"amount3"  : 1,
		"file3"    : "/obj/gift/xiandan",
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
		"file1"    : "/obj/gift/unknowdan",
	]) );
	set( "build", 3803 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room644",
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
