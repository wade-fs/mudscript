inherit ROOM;
void create() {
	set( "short", "五行區" );
	set( "object", ([
		"amount3"  : 1,
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount4"  : 1,
		"amount5"  : 1,
		"file1"    : "/obj/gift/shenliwan",
	]) );
	set( "build", 5121 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room624.c",
		"west"      : "/open/clan/sky-wu-chi/room/room623.c",
		"north"     : "/open/clan/sky-wu-chi/room/room642",
		"south"     : "/open/clan/sky-wu-chi/room/room557.c",
	]) );
	set( "long", @LONG
以後再補以後再補以後再補以後再補以後再補以後再補以後再補以後再補
以後再補以後再補以後再補以後再補以後再補以後再補以後再補以後再補
以後再補以後再補以後再補以後再補以後再補以後再補以後再補以後再補
以後再補以後再補以後再補以後再補以後再補以後再補以後再補以後再補
以後再補以後再補以後再補以後再補以後再補以後再補以後再補以後再補
LONG);
	setup();
	replace_program(ROOM);
}
