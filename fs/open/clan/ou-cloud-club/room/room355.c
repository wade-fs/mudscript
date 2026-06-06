inherit ROOM;
void create() {
	set( "short", "金絲貓" );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room133",
	]) );
	set( "object", ([
		"amount5"  : 130,
		"amount1"  : 10,
		"file3"    : "/open/ping/obj/poison_pill",
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"file8"    : "/open/scholar/obj/icefan",
		"amount8"  : 1,
		"file2"    : "/open/capital/obj/icer",
		"amount6"  : 6,
		"file10"   : "/open/fire-hole/obj/r-pill",
		"amount9"  : 1,
		"amount4"  : 1,
		"amount10" : 1,
		"amount7"  : 1,
		"file1"    : "/open/fire-hole/obj/b-pill",
		"file7"    : "/open/mon/obj/ghost-claw",
		"amount3"  : 19,
		"file6"    : "/open/magic-manor/ghost/obj/trigram-pill",
	]) );
	set( "build", 10122 );
	set( "light_up", 1 );
	set( "long", @LONG
喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵
喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵
喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵
喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵
喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵
喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵喵


LONG);
	setup();
	replace_program(ROOM);
}
