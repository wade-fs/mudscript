inherit ROOM;
void create() {
	set( "short", "$HIW$當舖$HIR$ソ$HIC$主人臥房$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/wu/obj/figring",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"amount7"  : 1,
		"file9"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount6"  : 1,
		"file2"    : "/open/firedancer/npc/eq/r_pants",
		"file7"    : "/open/firedancer/npc/eq/r_hands",
		"amount3"  : 1,
		"file1"    : "/open/wu/npc/obj/armband",
		"amount5"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/mon/obj/ghost-helmet",
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/firedancer/npc/eq/r_boots",
		"file10"   : "/open/sky/obj/lucky_grasslink",
		"file6"    : "/open/mon/obj/ghost-legging",
	]) );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room82",
	]) );
	set( "light_up", 1 );
	set( "build", 10046 );
	set( "long", @LONG
這裡是$HIW$當舖$HIR$ソ$HIC$主人$NOR$韓諾的房間，這裡十分的寬敞但四周並沒有窗戶，一張高
級的古董床上放著一張高級天蠶絲被，被上還用金絲線點綴縫紉而成，房間的前
面有個一人高三人寬的酒櫃，裡面擺滿了各式各樣的陳年好酒不管是西洋或是中
國的品種都有，旁邊還有著一台唱片機，上面播著３０年代的上海老歌，整個房
間帶給人一翻古老的氣息，令人不禁思考這個當舖主人到底是怎樣的一個人！
LONG);
	setup();
	replace_program(ROOM);
}
