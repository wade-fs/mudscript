inherit ROOM;
void create() {
	set( "short", "$RED$雜$CYN$物$GRN$倉$YEL$庫$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"file8"    : "/open/common/obj/liz_meat",
		"amount8"  : 1,
		"file2"    : "/open/common/obj/liz_meat",
		"amount6"  : 1,
		"file4"    : "/open/common/obj/liz_meat",
		"amount4"  : 1,
		"amount10" : 1,
		"file10"   : "/open/common/obj/liz_meat",
		"file3"    : "/open/common/obj/liz_meat",
		"amount2"  : 1,
		"file6"    : "/open/common/obj/liz_meat",
		"file1"    : "/open/common/obj/liz_meat",
		"file7"    : "/open/common/obj/liz_meat",
		"amount3"  : 1,
		"amount7"  : 1,
	]) );
	set( "owner", "auo" );
	set( "build", 10619 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room195",
	]) );
	set( "long", @LONG
這裡存放著一些有用的道具,魔龍鱗可從任何地方瞬間傳送到魔界,對於被困在某處或
是經常到魔界練功的人相當方便,火蜥蝪肉則可以吃250次,每次上線只要拿一個就吃不
完了,還有聚玄靈陽心及散玄冥陰心,據說是開啟天靈地界必備的道具,另外也有些從天
而降的仙丹,也都被收集到這裡存放

LONG);
	setup();
	replace_program(ROOM);
}
