inherit ROOM;
void create() {
	set( "short", "彰化高中" );
	set( "owner", "sai" );
	set( "object", ([
		"file2"    : "/open/killer/headkill/obj/world_dag",
		"amount1"  : 11,
		"file10"   : "/open/killer/headkill/obj/world_dag",
		"file1"    : "/open/killer/obj/s_pill",
		"file8"    : "/open/poison/obj/armband1",
		"amount3"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/killer/obj/fire-knife",
		"amount4"  : 1,
		"amount8"  : 1,
		"amount5"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"file6"    : "/open/killer/headkill/obj/world_dag",
		"amount6"  : 1,
		"file7"    : "/open/killer/headkill/obj/world_dag",
		"file3"    : "/open/ping/obj/chilin_legging",
		"file4"    : "/open/sky/obj/lucky_grasslink",
	]) );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room87.c",
		"add"       : "/open/clan/ou-cloud-club/room/room356",
	]) );
	set( "build", 10043 );
	set( "light_up", 1 );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
