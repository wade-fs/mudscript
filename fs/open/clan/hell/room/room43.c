inherit ROOM;
void create() {
	set( "short", "$HIC$kalin$HIW$的$HIG$雞絲頭2$NOR$" );
	set( "object", ([
		"file1"    : "/open/mon/obj/ghost-helmet",
		"amount6"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file9"    : "/open/mon/obj/ghost-helmet",
		"file3"    : "/open/mon/obj/ghost-helmet",
		"file8"    : "/open/mon/obj/ghost-helmet",
		"file6"    : "/open/mon/obj/ghost-helmet",
		"amount10" : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/mon/obj/ghost-helmet",
		"amount5"  : 1,
		"file10"   : "/open/mon/obj/ghost-helmet",
		"amount9"  : 1,
		"file5"    : "/open/mon/obj/ghost-helmet",
		"amount8"  : 1,
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount1"  : 1,
		"file7"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "owner", "blur" );
	set( "build", 11202 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room96",
		"east"      : "/open/clan/hell/room/room55.c",
		"south"     : "/open/clan/hell/room/room4.c",
	]) );
	set( "long", @LONG
嗯..
kalin 自從sui後,一心想中興射手,好不容易練到375one
但..但.....連master 廢 ba 都打不贏....
嗚....如今kalin只能賣賣公益彩券維生...
往日的妖刀風采不在...只能盼望小弟大飛能振作...
幫kalin把銅鑼灣扛霸子的地位要回來...
LONG);
	setup();
	replace_program(ROOM);
}
