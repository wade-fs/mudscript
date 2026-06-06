inherit ROOM;
void create() {
	set( "short", "『Item』收藏二館" );
	set( "owner", "yuki" );
	set( "object", ([
		"amount4"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount7"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount5"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount3"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount9"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount1"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount2"  : 1,
	]) );
	set( "build", 10018 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room343",
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
