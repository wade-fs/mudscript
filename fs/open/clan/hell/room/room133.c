inherit ROOM;
void create() {
	set( "short", "SSC2" );
	set( "owner", "vatsu" );
	set( "object", ([
		"amount3"  : 2,
		"amount8"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/sky/obj1/wind_emblem",
		"amount10" : 1,
		"file3"    : "/open/fire-hole/obj/b-pill",
		"file8"    : "/open/killer/headkill/obj/w_dag",
		"file1"    : "/open/killer/obj/bellstar",
		"file9"    : "/open/killer/headkill/obj/i_dag",
		"amount7"  : 1100,
		"file2"    : "/open/killer/obj/rock",
		"amount2"  : 1,
		"amount1"  : 29,
		"file10"   : "/daemon/class/fighter/ywleg",
		"amount4"  : 1,
		"file7"    : "/open/killer/obj/s_pill",
		"amount5"  : 1,
		"file4"    : "/open/start/obj/thunder_hat",
	]) );
	set( "light_up", 1 );
	set( "build", 10980 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room95.c",
		"west"      : "/open/clan/hell/room/room139",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
