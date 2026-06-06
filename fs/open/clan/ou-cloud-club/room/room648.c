inherit ROOM;
void create() {
	set( "short", "$HIG$丹$HIM$藥$HIC$房$NOR$" );
	set( "object", ([
		"file6"    : "/open/wind-rain/obj/sun_red_cloth",
		"file5"    : "/open/mogi/castle/obj/lochagem",
		"amount7"  : 1,
		"file10"   : "/open/wind-rain/obj/sun_red_cloth",
		"amount4"  : 1,
		"file7"    : "/open/wind-rain/obj/sun_red_cloth",
		"file1"    : "/open/mogi/castle/obj/lochagem",
		"file3"    : "/open/mogi/castle/obj/lochagem",
		"amount3"  : 1,
		"file9"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount1"  : 1,
		"file4"    : "/open/mogi/castle/obj/lochagem",
		"amount5"  : 1,
		"amount9"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/mogi/castle/obj/lochagem",
		"file8"    : "/open/wind-rain/obj/sun_red_cloth",
	]) );
	set( "owner", "enter" );
	set( "build", 10246 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room649",
		"west"      : "/open/clan/ou-cloud-club/room/room647",
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
