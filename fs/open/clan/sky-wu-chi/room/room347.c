inherit ROOM;
void create() {
	set( "short", "夏雷藏書閣" );
	set( "owner", "roboo" );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room345",
	]) );
	set( "object", ([
		"file2"    : "/open/scholar/obj/icefan",
		"file4"    : "/open/capital/guard/gring",
		"file3"    : "/open/tendo/obj/lucloth",
		"amount4"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"file1"    : "/open/mon/obj/ghost-claw",
	]) );
	set( "build", 10003 );
	set( "long", @LONG
    這個房間的牆上有許多像抽屜的小閣子，裡頭不知道是放了些什
麼，你向在這裡研究古書的夏雷請教，才知道原來這裡的小抽屜保存
著各種古文物，包括一些石碑、石版、和古書籍，這些都是歷史價值
極高的物品，而古學家－小宇先生正是在這裡研究這些鮮為人知的遠
古資料並將之著作成書。
LONG);
	setup();
	replace_program(ROOM);
}
