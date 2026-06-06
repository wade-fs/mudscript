inherit ROOM;
void create() {
	set( "short", "愜意人生晶華樓" );
	set( "owner", "edyln" );
	set( "object", ([
		"file9"    : "/open/killer/obj/atman_pill",
		"amount6"  : 179,
		"amount1"  : 55,
		"amount4"  : 184,
		"amount2"  : 7,
		"file5"    : "/open/fire-hole/obj/g-pill",
		"file1"    : "/open/fire-hole/obj/r-pill",
		"file2"    : "/obj/stone/jiao",
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"amount3"  : 22,
		"file4"    : "/obj/stone/powder",
		"file3"    : "/obj/stone/suipian",
		"amount7"  : 96,
		"amount8"  : 3,
		"file7"    : "/open/fire-hole/obj/w-pill",
		"amount9"  : 11411,
		"amount5"  : 339,
		"file8"    : "/open/ping/obj/poison_pill",
	]) );
	set( "build", 10005 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room581",
	]) );
	set( "long", @LONG
進入一棟裝潢頗有氣質，擺放來自世界各地收集的珍奇古玩。牆上還掛著
一幅書法：『中歲頗好道，晚家南山陲。興來每獨往，勝事空自知。行到水窮
處，坐看雲起時。偶然值林叟，談笑無還期。』原來這是這屋子的主人晶華下
午茶所期盼的生活境界。正值而立之年，已經為了能在未來達到愜意人生的境
界而努力中。

LONG);
	setup();
	replace_program(ROOM);
}
