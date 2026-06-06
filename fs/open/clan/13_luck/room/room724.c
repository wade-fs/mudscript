inherit ROOM;
void create() {
	set( "short", "少年輕狂熱血居" );
	set( "owner", "rededyln" );
	set( "object", ([
		"amount6"  : 1,
		"file10"   : "/obj/gift/unknowdan",
		"amount10" : 1,
		"amount9"  : 1,
		"amount5"  : 21,
		"file3"    : "/open/fire-hole/obj/r-pill",
		"file8"    : "/open/fire-hole/obj/w-pill",
		"amount3"  : 214,
		"file4"    : "/obj/gift/xiandan",
		"file2"    : "/open/fire-hole/obj/g-pill",
		"file1"    : "/open/ping/obj/poison_pill",
		"file6"    : "/obj/gift/shenliwan",
		"amount1"  : 426,
		"amount4"  : 1,
		"amount2"  : 504,
		"file5"    : "/open/mogi/castle/obj/sspill",
		"file9"    : "/open/capital/guard/gring",
		"amount8"  : 34,
	]) );
	set( "build", 10168 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room581",
	]) );
	set( "long", @LONG
『簫中弦音藏柔情，劍下腥血記恨仇。來去洶湧需揮劍，去向纏綿可負簫
。』這是這間簡陋居室主人的寫照。雖說人不輕狂枉少年，但對小狂戰來說，
輕狂的少年時代總是有著數不完的輕狂舉動，常令人氣結。但自從遇到他生命
中的剋星後，也會有柔情的一面。就如同詩中所云，弦音中自有一番柔情之意。

LONG);
	setup();
	replace_program(ROOM);
}
