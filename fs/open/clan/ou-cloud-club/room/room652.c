inherit ROOM;
void create() {
	set( "short", "$HIG$丹$HIM$藥$HIC$房$NOR$" );
	set( "object", ([
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"amount6"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/beggar/obj/hands",
		"amount7"  : 1,
		"file9"    : "/open/beggar/obj/hands",
		"amount3"  : 1,
		"file5"    : "/open/beggar/obj/hands",
		"amount2"  : 1,
		"file6"    : "/open/beggar/obj/hands",
		"file7"    : "/open/beggar/obj/hands",
		"amount5"  : 1,
		"amount9"  : 1,
		"amount1"  : 1,
	]) );
	set( "owner", "enter" );
	set( "build", 10902 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room653",
		"west"      : "/open/clan/ou-cloud-club/room/room651",
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
