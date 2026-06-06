inherit ROOM;
void create() {
	set( "short", "雪兒小窩" );
	set( "owner", "turtle" );
	set( "object", ([
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"amount6"  : 100,
		"file6"    : "/open/gsword/obj/ff_pill",
		"amount7"  : 1,
		"file10"   : "/open/magic-manor/obj/magic-sign",
		"file2"    : "/open/mogi/castle/obj/sspill",
		"amount9"  : 1,
		"amount2"  : 331,
		"file9"    : "/open/gblade/mob/lotch",
		"amount4"  : 400,
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount5"  : 1,
		"amount10" : 1,
		"file7"    : "/open/killer/obj/soul-hands",
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
		"amount8"  : 1,
		"file3"    : "/open/mon/obj/mon-pill",
		"file5"    : "/open/magic-manor/obj/sun-heart",
		"amount1"  : 736,
		"amount3"  : 790,
	]) );
	set( "build", 10220 );
	set( "exits", ([
		"add"       : "/open/clan/ou-cloud-club/room/room769",
		"down"      : "/open/clan/ou-cloud-club/room/room83.c",
	]) );
	set( "long", @LONG
這裡是雪兒的天堂，每個人來到這裡都能感覺到歡樂的氣氛。小窩當中佇立
著一座十分漂亮的噴水池，你可以看到白雪公主跟七個小矮人正熱情的跟你打招
呼呢。米老鼠跟唐老鴨手上拿著汽球高興地歡迎你來到這快樂的天堂。
LONG);
	setup();
	replace_program(ROOM);
}
