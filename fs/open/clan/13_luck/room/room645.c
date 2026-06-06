inherit ROOM;
void create() {
	set( "short", "天地金陣" );
	set( "object", ([
		"file10"   : "/open/wind-rain/obj/sun_red_cloth",
		"file9"    : "/open/poison/obj/armband1",
		"amount3"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/mon/obj/ghost-helmet",
		"file8"    : "/daemon/class/blademan/obj/shield",
		"amount7"  : 1,
		"file3"    : "/open/mon/obj/ghost-cloak",
		"amount8"  : 1,
		"file7"    : "/open/wu/obj/figring",
		"amount9"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"amount4"  : 1,
		"file4"    : "/open/tendo/obj/chaosbelt",
		"file2"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
		"file5"    : "/open/sky/obj/lucky_grasslink",
	]) );
	set( "build", 10204 );
	set( "light_up", 1 );
	set( "owner", "soul" );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room644",
		"south"     : "/open/clan/13_luck/room/room646",
	]) );
	set( "long", @LONG

╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ ╭╮
╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯ ╰╯╰╮
    這是天地五行的『金』陣，上引九天之氣，下通地
獄之火。四處金光閃閃，照得你眼睛都睜不開，腦袋中
幻影叢生，讓你不得不暗運內力，鎮攝自己不安的心，
才能繼續前進。
╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╯
╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯

LONG);
	setup();
	replace_program(ROOM);
}
