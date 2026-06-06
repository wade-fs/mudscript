inherit ROOM;
void create() {
	set( "short", "$HIG$丹$HIM$藥$HIC$房$NOR$" );
	set( "owner", "enter" );
	set( "object", ([
		"file9"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount9"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount1"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount8"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount7"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount2"  : 1,
		"amount5"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount10" : 1,
		"amount6"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-leggings",
	]) );
	set( "build", 10015 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room656",
		"west"      : "/open/clan/ou-cloud-club/room/room654.c",
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
