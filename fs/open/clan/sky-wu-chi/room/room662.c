inherit ROOM;
void create() {
	set( "short", "五塔準備房" );
	set( "object", ([
		"amount4"  : 1,
		"amount3"  : 1,
		"amount10" : 1,
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount1"  : 1,
		"file5"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file8"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file10"   : "/open/magic-manor/obj/fon-sky-sword",
		"amount5"  : 1,
		"file3"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file2"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount2"  : 1,
		"file6"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount6"  : 1,
		"file1"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file4"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount8"  : 1,
		"amount9"  : 1,
	]) );
	set( "owner", "cdrom" );
	set( "build", 11182 );
	set( "exits", ([
		"out"       : "/open/clan/sky-wu-chi/room/room658",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
