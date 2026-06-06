inherit ROOM;
void create() {
	set( "short", "阿華田二家" );
	set( "object", ([
		"file10"   : "/obj/gift/shenliwan",
		"amount4"  : 2,
		"amount6"  : 1226,
		"amount2"  : 1,
		"amount1"  : 1,
		"file7"    : "/obj/gift/bingtang",
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file5"    : "/open/killer/obj/s_pill",
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"file1"    : "/obj/gift/hobowdan",
		"amount7"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"file2"    : "/obj/gift/lingzhi",
		"file8"    : "/obj/gift/hobowdan",
		"file9"    : "/obj/gift/lingzhi",
		"amount3"  : 1,
		"amount5"  : 255,
		"file3"    : "/open/mogi/castle/obj/fire_book",
	]) );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room404",
		"west"      : "/open/clan/ou-cloud-club/room/room414.c",
	]) );
	set( "owner", "ovaltine" );
	set( "build", 10174 );
	set( "light_up", 1 );
	set( "long", @LONG
-------------------------------------------
-----------------------------------------------
-----------------------------------------------
-----------------------------------------------
-----------------------------------------------
-----------------------------------------------
-----------------------------------------------
LONG);
	setup();
	replace_program(ROOM);
}
