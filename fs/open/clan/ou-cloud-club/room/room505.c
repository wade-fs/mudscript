inherit ROOM;
void create() {
	set( "short", "剛強的大廳" );
	set( "owner", "roboii" );
	set( "object", ([
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/fire-hole/obj/g-pill",
		"amount6"  : 135,
		"amount3"  : 96,
		"file4"    : "/open/fire-hole/obj/p-pill",
		"amount5"  : 1,
		"file3"    : "/open/fire-hole/obj/b-pill",
		"amount7"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"amount4"  : 49,
		"file5"    : "/open/magic-manor/obj/lunar-heart",
		"file6"    : "/open/killer/obj/atman_pill",
		"amount9"  : 7,
		"file1"    : "/open/fire-hole/obj/r-pill",
		"amount10" : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 86,
	]) );
	set( "build", 10429 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room501",
		"west"      : "/open/clan/ou-cloud-club/room/room503.c",
		"east"      : "/open/clan/ou-cloud-club/room/room504.c",
		"north"     : "/open/clan/ou-cloud-club/room/room502.c",
		"out"       : "/open/clan/ou-cloud-club/room/room253",
	]) );
	set( "long", @LONG
    這裡是中央大街和東西兩大街的交叉口 . 這裡每到晚上會形
成夜市 , 販賣的商品種類層出不窮 , 時常會有些各國的商人到
此交易 , 使楓林港抹上繽紛的異國情調 , 來到這裡你要留心點
 , 說不定能買到奇珍異品 .
 , 說不定能買到奇珍異品 .
LONG);
	setup();
	replace_program(ROOM);
}
