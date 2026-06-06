inherit ROOM;
void create() {
	set( "short", "一隻筆實驗室" );
	set( "owner", "kanon" );
	set( "object", ([
		"amount10" : 1,
		"amount9"  : 1,
		"file7"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"amount8"  : 1,
		"file3"    : "/open/ghost-hole/obj/wind-spirit",
		"amount5"  : 1,
		"amount3"  : 1,
		"file6"    : "/open/capital/obj/blade2",
		"amount4"  : 1395,
		"amount6"  : 1,
		"file5"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 1,
		"file10"   : "/open/magic-manor/obj/lin-cloud-fan",
		"file2"    : "/open/mogi/castle/obj/fire_book",
		"amount1"  : 1,
		"file1"    : "/daemon/class/fighter/figring",
		"amount2"  : 1,
		"file9"    : "/open/capital/obj/4-3",
	]) );
	set( "build", 12480 );
	set( "item_desc", ([
		"pen" : @ITEM
一支最新研發的筆被放在這裡,等待者研發人員去測試
請勿亂拿此筆去做不正當的用途
ITEM,
	]) );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room425",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
此處是ctx的原子筆製造實驗中心,這裡專門負責做出最新
且最好的筆,只要是所有看過的筆,都是從這邊研發出來的,所有
研發出來的筆都經過嚴格測試,而目前地上就擺了一支新研發等
待研究人員測試的新產品。

一支筆(A pen)

LONG);
	setup();
	replace_program(ROOM);
}
