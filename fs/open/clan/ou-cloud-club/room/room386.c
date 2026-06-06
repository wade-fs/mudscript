inherit ROOM;
void create() {
	set( "short", "$HIR$波-地下錢莊(10)$NOR$" );
	set( "owner", "perth" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room174",
		"south"     : "/open/clan/ou-cloud-club/room/room387.c",
		"north"     : "/open/clan/ou-cloud-club/room/room385",
	]) );
	set( "object", ([
		"amount6"  : 1,
		"file5"    : "/open/magic-manor/obj/water-ball",
		"amount10" : 1,
		"amount3"  : 1,
		"file10"   : "/obj/gift/unknowdan",
		"amount4"  : 1,
		"file6"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount5"  : 1,
		"file8"    : "/obj/gift/xiandan",
		"amount8"  : 1,
		"amount9"  : 1,
		"file4"    : "/obj/gift/shenliwan",
		"amount7"  : 1,
		"file9"    : "/obj/gift/unknowdan",
		"file1"    : "/open/magic-manor/obj/soil-ball",
		"file2"    : "/open/magic-manor/obj/wood-ball",
		"file7"    : "/open/magic-manor/obj/water-ball",
		"file3"    : "/obj/gift/shenliwan",
		"amount1"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 13853 );
	set( "long", @LONG
股金融股金融股金融股金融股金融股金融股金融股金融股
金融股金融股金融股金融股金融股金融股金融股金融股金融股
金融股金融股金融股金融股金融股金融股金融股金融股金融股
金融股金融股金融股金融股金融股金融股金融股金融股金融股
金融股金融股金融股金融股金融股金融股金融股金融股金融股
金融股金融股金融股金融股金融股金融股金融股金融股金融股

LONG);
	setup();
	replace_program(ROOM);
}
