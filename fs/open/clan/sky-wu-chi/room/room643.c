inherit ROOM;
void create() {
	set( "short", "光碟片-換裝室" );
	set( "object", ([
		"file4"    : "/open/magic-manor/obj/golden-ball",
		"amount8"  : 1,
		"amount4"  : 1,
		"file6"    : "/open/magic-manor/obj/soil-ball",
		"amount7"  : 1,
		"file3"    : "/open/magic-manor/obj/water-ball",
		"amount10" : 1,
		"amount1"  : 1,
		"amount2"  : 722,
		"amount3"  : 1,
		"file7"    : "/open/magic-manor/obj/fire-ball",
		"file8"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount5"  : 1,
		"file10"   : "/obj/gift/hobowdan",
		"file1"    : "/open/common/obj/mass",
		"file9"    : "/open/killer/headkill/obj/world_dag",
		"amount9"  : 1,
		"file5"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file2"    : "/open/killer/obj/atman_pill",
		"amount6"  : 1,
	]) );
	set( "build", 10600 );
	set( "owner", "cdrom" );
	set( "exits", ([
		"up"        : "/open/clan/sky-wu-chi/room/room237",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
