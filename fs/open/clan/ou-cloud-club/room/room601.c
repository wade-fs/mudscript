inherit ROOM;
void create() {
	set( "short", "$HIY$仙丹$NOR$($HIG$dan$NOR$)" );
	set( "object", ([
		"amount6"  : 1,
		"file3"    : "/obj/gift/xiandan",
		"file6"    : "/obj/gift/xiandan",
		"file9"    : "/obj/gift/xiandan",
		"amount7"  : 828,
		"file8"    : "/obj/gift/xiandan",
		"file1"    : "/obj/gift/xiandan",
		"file10"   : "/open/mogi/castle/obj/sspill",
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"file2"    : "/obj/gift/xiandan",
		"amount8"  : 1,
		"amount5"  : 1,
		"file5"    : "/obj/gift/xiandan",
		"amount2"  : 1,
		"amount10" : 575,
		"amount3"  : 1,
		"amount1"  : 1,
		"amount4"  : 1,
		"file4"    : "/obj/gift/xiandan",
		"amount9"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10068 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room610",
		"out"       : "/open/clan/ou-cloud-club/room/room4",
		"south"     : "/open/clan/ou-cloud-club/room/room774",
	]) );
	set( "long", @LONG
從你踏入此室時，一股淡淡清香撲鼻而來，只見地上
堆積著一堆堆的藥草，都是江湖上夢寐以求的藥草，而牆
邊壁櫥內更是放滿著各式各樣的藥丹，每一樣都是稀有難
求的，而此處竟堆積著如此多的丹藥，若非親眼看見還真
無法相信，可見傲雲山莊裡擁有太多的高手存在了。

LONG);
	setup();
	replace_program(ROOM);
}
