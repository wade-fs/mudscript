inherit ROOM;
void create() {
	set( "short", "$YEL$洗髓丹$NOR$($HIG$dan$NOR$)" );
	set( "object", ([
		"file7"    : "/obj/gift/xisuidan",
		"file1"    : "/obj/gift/xisuidan",
		"file4"    : "/obj/gift/xisuidan",
		"amount2"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"file3"    : "/obj/gift/xisuidan",
		"file10"   : "/obj/gift/xisuidan",
		"amount8"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"file9"    : "/obj/gift/xisuidan",
		"file5"    : "/obj/gift/xisuidan",
		"file8"    : "/obj/gift/xisuidan",
		"amount7"  : 1,
		"file2"    : "/obj/gift/xisuidan",
		"file6"    : "/obj/gift/xisuidan",
		"amount5"  : 1,
		"amount4"  : 1,
	]) );
	set( "owner", "enter" );
	set( "build", 11998 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room610",
		"west"      : "/open/clan/ou-cloud-club/room/room608.c",
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
