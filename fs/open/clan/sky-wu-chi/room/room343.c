inherit ROOM;
void create() {
	set( "short", "『Item』收藏一館" );
	set( "owner", "yuki" );
	set( "object", ([
		"amount3"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount8"  : 1,
		"amount4"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount7"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount9"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount2"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount10" : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount1"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 10040 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room413",
		"north"     : "/open/clan/sky-wu-chi/room/room122.c",
	]) );
	set( "long", @LONG
這裡收藏著『屠龍刀』從各地收集而來的丹藥。天山
雪蓮、高麗人蔘、東海冰精都是這裡的常見物品。除了一
些常見的丹藥外，如果你也有多餘稀奇的丹藥，也許大家
可以來交換一下。書櫃中有本傷寒雜病論的精裝本，是不
錯的課外讀物。
LONG);
	setup();
	replace_program(ROOM);
}
