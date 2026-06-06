inherit ROOM;
void create() {
	set( "short", "聚靈道準備室" );
	set( "object", ([
		"amount4"  : 43,
		"file3"    : "/open/magic-manor/obj/sun-heart",
		"file2"    : "/open/magic-manor/obj/magic-sign",
		"amount5"  : 1,
		"amount2"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/magic-manor/obj/sun-heart",
		"file4"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/obj/lunar-heart",
		"file5"    : "/open/magic-manor/obj/lunar-heart",
	]) );
	set( "owner", "cdrom" );
	set( "build", 10151 );
	set( "exits", ([
		"r2"        : "/open/clan/sky-wu-chi/room/room660.c",
		"r1"        : "/open/clan/sky-wu-chi/room/room659.c",
		"r3"        : "/open/clan/sky-wu-chi/room/room661.c",
		"r4"        : "/open/clan/sky-wu-chi/room/room662",
		"out"       : "/open/clan/sky-wu-chi/room/room297.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
