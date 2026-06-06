inherit ROOM;
void create() {
	set( "short", "寒冰房" );
	set( "object", ([
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount5"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount4"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount3"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount1"  : 1,
		"amount6"  : 1,
	]) );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room270",
	]) );
	set( "build", 10272 );
	set( "light_up", 1 );
	set( "long", @LONG

    寒冰，乃是千年冰雪所成，所以都不會溶化，而此物又為風行山寨
的寨主夫人所有，美貌驚為天人，但是有秀麗的外表，也有高強的武功
，讓多少想跟他三個女的人，慘死在他的手中，身上有著段家他討厭的
定人絕技，讓人防不勝防。

LONG);
	setup();
	replace_program(ROOM);
}
