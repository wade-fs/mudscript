inherit ROOM;
void create() {
	set( "short", "$HIG$神力丸$NOR$($HIG$shenli wan$NOR$)" );
	set( "object", ([
		"file8"    : "/obj/gift/xiandan",
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"file5"    : "/obj/gift/xisuidan",
		"amount8"  : 1,
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"amount9"  : 800,
		"amount1"  : 800,
		"amount5"  : 1,
		"amount6"  : 888,
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 800,
		"file2"    : "/open/mogi/castle/obj/sspill",
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"amount2"  : 800,
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"amount3"  : 800,
		"file9"    : "/open/mogi/castle/obj/ninepill",
		"amount4"  : 800,
		"amount10" : 800,
	]) );
	set( "owner", "enter" );
	set( "build", 10645 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room605",
		"west"      : "/open/clan/ou-cloud-club/room/room603.c",
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
