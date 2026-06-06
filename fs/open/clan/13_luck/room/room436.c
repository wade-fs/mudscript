inherit ROOM;
void create() {
	set( "short", "種族及國家5" );
	set( "object", ([
		"file3"    : "/obj/gift/shenliwan",
		"file4"    : "/obj/gift/shenliwan",
		"file5"    : "/obj/gift/shenliwan",
		"file9"    : "/obj/gift/shenliwan",
		"file7"    : "/obj/gift/shenliwan",
		"amount6"  : 1,
		"amount2"  : 1,
		"file10"   : "/obj/gift/shenliwan",
		"amount5"  : 1,
		"amount10" : 1,
		"file6"    : "/obj/gift/shenliwan",
		"amount1"  : 1,
		"file1"    : "/obj/gift/shenliwan",
		"file8"    : "/obj/gift/shenliwan",
		"file2"    : "/obj/gift/shenliwan",
		"amount3"  : 1,
		"amount7"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"amount4"  : 1,
	]) );
	set( "owner", "dfyw" );
	set( "build", 10046 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room440",
	]) );
	set( "long", @LONG

 沼族
 全身佈滿鱗片的種族，看起來就像是比大的爬蟲類。智能較差，有著特殊社會組
 織以及狂熱的宗教信仰。

 龍神島
 沼族，又稱兩棲族，散居大陸各處，智能較差，又少與外界接觸野食因為食物或
 金錢，成為自由傭兵。龍神島的沼族憑狂熱組成軍隊，四處討伐*神之大敵*沼族
 沒有國家意識，只有稱為滾客的龍神島技師相當於領導。

LONG);
	setup();
	replace_program(ROOM);
}
