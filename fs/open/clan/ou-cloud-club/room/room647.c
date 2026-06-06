inherit ROOM;
void create() {
	set( "short", "$HIG$丹$HIM$藥$HIC$房$NOR$" );
	set( "object", ([
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 1,
		"amount7"  : 1,
		"file4"    : "/open/capital/obj/4-3",
		"file2"    : "/open/capital/obj/4-3",
		"amount8"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/capital/obj/4-3",
		"amount2"  : 1,
		"amount4"  : 1,
		"amount10" : 867,
		"amount5"  : 1,
		"amount6"  : 1,
		"file9"    : "/open/capital/obj/4-3",
		"file8"    : "/open/capital/obj/4-3",
		"file6"    : "/open/sky/obj/lucky_grasslink",
		"amount9"  : 1,
		"file3"    : "/open/capital/obj/4-3",
		"file1"    : "/open/capital/obj/4-3",
		"file5"    : "/open/capital/obj/4-3",
	]) );
	set( "owner", "enter" );
	set( "build", 10104 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room648",
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
