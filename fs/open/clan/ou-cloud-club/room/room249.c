inherit ROOM;
void create() {
	set( "short", "duramax" );
	set( "owner", "neonn" );
	set( "object", ([
		"amount10" : 1,
		"file6"    : "/open/mon/obj/mon-pill",
		"file8"    : "/open/mon/obj/mon-pill",
		"amount4"  : 1,
		"file9"    : "/open/capital/obj/blade2",
		"amount6"  : 45,
		"amount2"  : 1,
		"amount7"  : 45,
		"file10"   : "/open/scholar/obj/icefan",
		"amount5"  : 1,
		"amount1"  : 3,
		"file2"    : "/open/killer/memory/static",
		"file1"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount3"  : 45,
		"amount8"  : 7,
		"amount9"  : 1,
		"file7"    : "/open/mon/obj/mon-pill",
		"file4"    : "/open/mon/obj/ghost-legging",
		"file3"    : "/open/mon/obj/mon-pill",
		"file5"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room16.c",
		"east"      : "/open/clan/ou-cloud-club/room/room405",
	]) );
	set( "build", 16235 );
	set( "light_up", 1 );
	set( "long", @LONG
這裡是傲雲山莊的高手們所居住的地方，傲雲山莊內的
人都居住於此，擁有濃烈的肅殺味道，所以，在這裡你要特
別的的小心謹慎，以免進入了不該進入的房間。

左邊是語情深(zuba)的房間，右邊則是炎龍(bleak)的房間。

LONG);
	setup();
	replace_program(ROOM);
}
