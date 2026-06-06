inherit ROOM;
void create() {
	set( "short", "$BYEL$變形學$BGRN$教室$NOR$" );
	set( "owner", "wateribbon" );
	set( "object", ([
		"amount6"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount7"  : 1,
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount5"  : 1,
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount1"  : 1,
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount9"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
	]) );
	set( "build", 10078 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room57",
	]) );
	set( "long", @LONG
變形學是難度相當高的一門學科,也是相當有用的技能,當你變成某一種動物
後就可擁有此動物的能力,像是變成老;鼠就可以在牆角挖洞,變成狗就可以
跑的快,這對學生而言是多麼炫的技能,但是學生們馬上就體會到要完全變形是
多麼困難的事,因為他們連將火柴變成針都得要傷透腦筋了

LONG);
	setup();
	replace_program(ROOM);
}
