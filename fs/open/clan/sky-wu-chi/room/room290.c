inherit ROOM;
void create() {
	set( "short", "『Pill』收藏二館" );
	set( "owner", "yuki" );
	set( "object", ([
		"file8"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file6"    : "/open/mon/obj/ghost-claw",
		"amount6"  : 1,
		"amount2"  : 155,
		"amount10" : 1,
		"amount7"  : 14,
		"amount8"  : 1,
		"amount9"  : 1,
		"file7"    : "/open/ping/obj/poison_pill",
		"amount4"  : 334,
		"amount3"  : 5,
		"file10"   : "/obj/gift/lingzhi",
		"file9"    : "/open/mon/obj/ghost-claw",
		"file2"    : "/open/killer/obj/s_pill",
		"file1"    : "/obj/stone/suipian",
		"file3"    : "/obj/stone/jiao",
		"file4"    : "/obj/stone/powder",
		"amount1"  : 36,
	]) );
	set( "build", 10170 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room344",
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
