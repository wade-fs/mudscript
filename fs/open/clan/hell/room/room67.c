inherit ROOM;
void create() {
	set( "short", "$HIY$魔龍鱗$HIW$之界$NOR$PART3" );
	set( "object", ([
		"amount9"  : 1,
		"amount10" : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "owner", "blur" );
	set( "build", 10957 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room56.c",
	]) );
	set( "long", @LONG

俗話說有一就有二...無三不成禮...
當然還是要努力的給它在蓋下去囉...
當大家快樂的用魔龍麟飛當小飛俠時...
別忘了感謝hell辛苦的勞工弟兄...
hell的經濟奇蹟就是由他們開創的...

所以讓我們一起來,大聲的說 : 啊~ 福氣啦!!

LONG);
	setup();
	replace_program(ROOM);
}
