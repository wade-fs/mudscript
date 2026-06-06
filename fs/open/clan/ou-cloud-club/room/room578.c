inherit ROOM;
void create() {
	set( "short", "新區域J-W" );
	set( "owner", "soldier" );
	set( "object", ([
		"amount6"  : 1,
		"amount1"  : 40,
		"amount7"  : 1,
		"file4"    : "/open/ping/obj/cloud_fan",
		"file2"    : "/open/capital/obj/4-1",
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"amount2"  : 1,
		"amount3"  : 35,
		"file7"    : "/obj/gift/xiandan",
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"file5"    : "/open/ping/obj/cloud_fan",
		"amount5"  : 1,
		"file6"    : "/open/ping/questsfan/obj/stone",
		"amount4"  : 1,
	]) );
	set( "build", 10201 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room574",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
