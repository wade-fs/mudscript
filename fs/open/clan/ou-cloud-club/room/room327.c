inherit ROOM;
void create() {
	set( "short", "$HIC$波-羽球場(7)$NOR$" );
	set( "owner", "perth" );
	set( "object", ([
		"amount2"  : 57,
		"file9"    : "/obj/gift/xiandan",
		"file6"    : "/open/magic-manor/obj/lunar-heart",
		"amount3"  : 1,
		"file4"    : "/obj/gift/shenliwan",
		"amount10" : 1,
		"file8"    : "/obj/gift/unknowdan",
		"file7"    : "/open/magic-manor/obj/sun-heart",
		"amount5"  : 1,
		"amount8"  : 1,
		"amount1"  : 1,
		"amount9"  : 1,
		"file3"    : "/obj/gift/xisuidan",
		"file5"    : "/obj/gift/shenliwan",
		"amount6"  : 1,
		"file1"    : "/obj/gift/xisuidan",
		"amount7"  : 1,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"file10"   : "/obj/gift/xiandan",
		"amount4"  : 1,
	]) );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room326",
		"east"      : "/open/clan/ou-cloud-club/room/room317",
		"north"     : "/open/clan/ou-cloud-club/room/room388.c",
	]) );
	set( "build", 10305 );
	set( "long", @LONG
羽球    羽球    羽球    羽球    羽球   
啪  啪  啪  啪  啪  啪  啪  啪  啪  啪  啪  啪
啪  啪  啪  啪  啪  啪  啪  啪  啪  啪  啪  啪
啪  啪  啪  啪  啪  啪  啪  啪  啪  啪  啪  啪
啪  啪  啪  啪  啪  啪  啪  啪  啪  啪  啪  啪
啪  啪  啪  啪  啪  啪  啪  啪  啪  啪  啪  啪

LONG);
	setup();
	replace_program(ROOM);
}
