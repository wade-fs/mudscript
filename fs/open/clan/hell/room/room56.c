inherit ROOM;
void create() {
	set( "short", "$HIY$魔龍鱗$HIW$之界$NOR$PART2 " );
	set( "object", ([
		"file8"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"amount9"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "owner", "blur" );
	set( "build", 10066 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room67.c",
		"west"      : "/open/clan/hell/room/room22.c",
	]) );
	set( "long", @LONG

原本魔龍麟之界只有一間...但大飛絕得不夠用...因為hell的每個人都是比懶的... :P
別打我喔~ 好啦..我招了..我是最懶的...
所以還是擴充區域吧...於是魔龍靈之界part2誕生....
wahaha
祝大家使用愉快....年年有今日...歲歲有今朝......
LONG);
	setup();
	replace_program(ROOM);
}
