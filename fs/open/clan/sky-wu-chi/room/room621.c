inherit ROOM;
void create() {
	set( "short", "五塔key" );
	set( "object", ([
		"file9"    : "/open/killer/obj/fire-knife",
		"amount9"  : 1,
		"file5"    : "/open/capital/guard/gring",
		"amount4"  : 1,
		"file6"    : "/open/mogi/castle/obj/blood-water",
		"file4"    : "/open/killer/headkill/obj/world_dag",
		"file2"    : "/open/killer/headkill/obj/world_dag",
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"amount7"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"file1"    : "/open/capital/guard/gring",
		"amount3"  : 1,
		"file7"    : "/open/killer/obj/fire-knife",
		"amount6"  : 1,
		"amount5"  : 1,
		"file10"   : "/open/killer/obj/fire-knife",
		"file8"    : "/open/killer/obj/fire-knife",
		"amount8"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10549 );
	set( "owner", "cdrom" );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room296",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
