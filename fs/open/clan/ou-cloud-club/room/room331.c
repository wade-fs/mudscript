inherit ROOM;
void create() {
	set( "short", "特力屋" );
	set( "owner", "dracula" );
	set( "object", ([
		"file6"    : "/open/fire-hole/obj/k-pill",
		"file7"    : "/open/gsword/obj1/blosword",
		"file4"    : "/open/sky/obj/lucky_grasslink",
		"amount4"  : 1,
		"file8"    : "/open/poison/obj/armband1",
		"amount2"  : 1,
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"amount7"  : 1,
		"file2"    : "/open/gsword/obj1/blosword",
		"amount1"  : 1,
		"file1"    : "/open/gsword/obj1/blosword",
		"amount9"  : 1,
		"amount6"  : 219,
		"amount3"  : 1,
		"amount8"  : 1,
		"file3"    : "/open/gsword/obj1/blosword",
	]) );
	set( "build", 23823 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room121",
		"add"       : "/open/clan/ou-cloud-club/room/room356",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
