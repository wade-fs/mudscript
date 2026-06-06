inherit ROOM;
void create() {
	set( "short", "『Pill』收藏一館" );
	set( "owner", "yuki" );
	set( "object", ([
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount4"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount2"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-armband",
	]) );
	set( "build", 12378 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room122.c",
		"north"     : "/open/clan/sky-wu-chi/room/room290",
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
