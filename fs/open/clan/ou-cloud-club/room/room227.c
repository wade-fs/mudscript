inherit ROOM;
void create() {
	set( "short", "雖然只能在這給你祝福，還是要祝你生日快樂!" );
	set( "object", ([
		"amount1"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"amount3"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/capital/obj/king-ring",
		"amount2"  : 1,
		"amount10" : 1,
		"amount4"  : 1,
		"file9"    : "/open/center/obj/gamble_book",
		"amount6"  : 1,
		"file8"    : "/open/magic-manor/obj/magic-sign",
		"amount9"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file4"    : "/open/sky/obj/lucky_grasslink",
		"amount8"  : 1,
		"file1"    : "/open/mon/obj/ghost-helmet",
		"file10"   : "/open/clan/area/home/hae_bag",
		"file7"    : "/open/capital/obj/king-cloth",
		"file5"    : "/open/mon/obj/ghost-claw",
	]) );
	set( "owner", "julio" );
	set( "light_up", 1 );
	set( "build", 10131 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room200.c",
		"east"      : "/open/clan/ou-cloud-club/room/room158",
	]) );
	set( "long", @LONG

記憶無法遺忘，只是將它收藏。
記憶無法遺忘，只是將它收藏。
記憶無法遺忘，只是將它收藏。
記憶無法遺忘，只是將它收藏。
記憶無法遺忘，只是將它收藏。
記憶無法遺忘，只是將它收藏。
記憶無法遺忘，只是將它收藏。
記憶無法遺忘，只是將它收藏。
LONG);
	setup();
	replace_program(ROOM);
}
