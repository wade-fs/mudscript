inherit ROOM;
void create() {
	set( "short", "家樂福" );
	set( "owner", "dracula" );
	set( "object", ([
		"amount7"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/wind-rain/obj/sun_red_cloth",
		"file3"    : "/open/scholar/obj/icefan",
		"amount8"  : 1,
		"file2"    : "/open/ping/obj/neck0",
		"file9"    : "/open/poison/obj/armband1",
		"amount4"  : 1,
		"amount10" : 1,
		"amount9"  : 1,
		"file8"    : "/obj/stone/jiao",
		"amount3"  : 1,
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"amount1"  : 1,
		"file4"    : "/open/scholar/obj/icefan",
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"file7"    : "/open/ping/obj/chilin_legging",
		"amount5"  : 1,
		"file10"   : "/daemon/class/blademan/obj/shield",
		"amount6"  : 1,
	]) );
	set( "build", 31172 );
	set( "exits", ([
		"add"       : "/open/clan/ou-cloud-club/room/room356",
		"west"      : "/open/clan/ou-cloud-club/room/room121.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
