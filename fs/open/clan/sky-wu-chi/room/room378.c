inherit ROOM;
void create() {
	set( "short", "gk eq-ring" );
	set( "owner", "cong" );
	set( "light_up", 1 );
	set( "object", ([
		"amount7"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount2"  : 1,
	]) );
	set( "build", 10089 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room97",
	]) );
	set( "long", @LONG

無顏獨上西樓,

月如鉤,

寂寞梧桐深院鎖清秋,

剪不斷,理還亂,是離愁,

別是一番滋味在心頭.



LONG);
	setup();
	replace_program(ROOM);
}
