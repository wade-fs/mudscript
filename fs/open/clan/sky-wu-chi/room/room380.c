inherit ROOM;
void create() {
	set( "short", "水晶宮前廳" );
	set( "owner", "poiiiiop" );
	set( "object", ([
		"file10"   : "/open/prayer/obj/boris-boots",
		"file4"    : "/daemon/class/blademan/obj/shield",
		"file5"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount3"  : 1,
		"file8"    : "/open/dancer/obj/yuawaist",
		"amount9"  : 1,
		"amount4"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/mon/obj/ghost-helmet",
		"amount10" : 1,
		"amount6"  : 1,
		"file9"    : "/open/wu/npc/obj/armband",
		"amount8"  : 1,
		"file7"    : "/open/mon/obj/ghost-cloak",
		"amount5"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/wu/obj/figring",
		"file3"    : "/open/mon/obj/ghost-legging",
	]) );
	set( "build", 10029 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room396",
	]) );
	set( "long", @LONG

當由睡夢中醒來，竟發現自己身處在一個超越現實
的地方中，眼前所見竟是許多立方體的房間所組合
而成，到處充滿致命陷阱，無論往那個方向走，卻
一直在原地打轉，找不到任何的出路，彷彿是一個
永遠走不出的迷宮，在極度的恐懼之下，心裡不由
的猜測這裡真是傳說中的龍宮嗎？

LONG);
	setup();
	replace_program(ROOM);
}
