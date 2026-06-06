inherit ROOM;
void create() {
	set( "short", "劍塚" );
	set( "owner", "pighead" );
	set( "object", ([
		"file8"    : "/daemon/class/bonze/puty_pullium",
		"file6"    : "/daemon/class/blademan/obj/shield",
		"amount6"  : 1,
		"file3"    : "/open/ping/obj/gold_hand",
		"file2"    : "/open/mon/obj/ghost-legging",
		"file1"    : "/open/gsword/obj/dragon-sword",
		"amount10" : 1,
		"amount3"  : 1,
		"file4"    : "/open/dancer/obj/yuawaist",
		"file9"    : "/open/scholar/obj/icefan",
		"amount1"  : 1,
		"file7"    : "/open/mon/obj/ghost-cloak",
		"amount5"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"amount9"  : 1,
		"amount2"  : 1,
		"amount8"  : 1,
		"file10"   : "/open/mogi/village/obj/mogi_ring",
		"amount4"  : 1,
	]) );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room267",
		"east"      : "/open/clan/13_luck/room/room100",
	]) );
	set( "build", 10186 );
	set( "light_up", 1 );
	set( "long", @LONG
這裡就是天下名劍最終歸位之所，一個白髮鬚鬚的老者正高坐石碑之
上。於各名劍中，因各劍士本身之修為興造詣，使各劍靈性迥然不同，只
見中央處擺設一五芒星陣，【魔流劍‧悟】被封印其中，只聞其劍發出陣
陣的嗡鳴聲響，其狀迥異於其它名劍，赫見四隻金龍衝天而起，分立四方
。守護並封印著【悟】，長久以來使一直由兜山大悟所看守並期望著有天
能駕禦此劍行走天下。

LONG);
	setup();
	replace_program(ROOM);
}
