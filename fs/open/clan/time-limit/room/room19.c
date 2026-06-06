inherit ROOM;
void create() {
	set( "short", "金牛宮" );
	set( "object", ([
		"file6"    : "/open/fire-hole/obj/b-pill",
		"amount7"  : 172,
		"amount5"  : 192,
		"file3"    : "/open/fire-hole/obj/p-pill",
		"file1"    : "/open/fire-hole/obj/y-pill",
		"file4"    : "/open/fire-hole/obj/g-pill",
		"amount4"  : 142,
		"amount3"  : 82,
		"amount1"  : 2,
		"amount2"  : 29,
		"file2"    : "/open/fire-hole/obj/k-pill",
		"amount6"  : 37,
		"file7"    : "/open/fire-hole/obj/w-pill",
		"file5"    : "/open/fire-hole/obj/r-pill",
	]) );
	set( "owner", "jar" );
	set( "build", 9931 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room190",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
