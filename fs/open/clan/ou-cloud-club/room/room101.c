inherit ROOM;
void create() {
	set( "short", "$HIG$丹$HIM$藥$HIC$房$NOR$" );
	set( "object", ([
		"amount4"  : 1307,
		"amount9"  : 896,
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"file6"    : "/open/fire-hole/obj/w-pill",
		"amount10" : 900,
		"file9"    : "/open/mogi/castle/obj/sspill",
		"amount8"  : 5700,
		"file3"    : "/open/fire-hole/obj/r-pill",
		"amount5"  : 2892,
		"file1"    : "/open/fire-hole/obj/p-pill",
		"amount6"  : 1358,
		"amount2"  : 68009,
		"file2"    : "/open/mon/obj/mon-pill",
		"amount7"  : 252,
		"file4"    : "/open/fire-hole/obj/k-pill",
		"amount1"  : 2602,
		"file7"    : "/open/fire-hole/obj/y-pill",
		"file5"    : "/open/fire-hole/obj/b-pill",
		"file8"    : "/open/killer/obj/s_pill",
		"amount3"  : 1000,
	]) );
	set( "owner", "enter" );
	set( "build", 10870 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room4.c",
		"north"     : "/open/clan/ou-cloud-club/room/room231.c",
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
