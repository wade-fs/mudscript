inherit ROOM;
void create() {
	set( "short", "欣幸運草環室" );
	set( "object", ([
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"amount3"  : 1,
		"amount9"  : 1,
		"amount2"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"amount4"  : 1,
		"amount7"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"file6"    : "/open/sky/obj/lucky_grasslink",
		"file10"   : "/open/sky/obj/lucky_grasslink",
		"file8"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10051 );
	set( "owner", "lts" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room399",
	]) );
	set( "long", @LONG
幸運草環(Lucky-grasslink)
幸運草環(Lucky-grasslink)
幸運草環(Lucky-grasslink)
幸運草環(Lucky-grasslink)
幸運草環(Lucky-grasslink)
幸運草環(Lucky-grasslink)
幸運草環(Lucky-grasslink)
幸運草環(Lucky-grasslink)
幸運草環(Lucky-grasslink)

LONG);
	setup();
	replace_program(ROOM);
}
