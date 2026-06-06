inherit ROOM;
void create() {
	set( "short", "師部大門" );
	set( "object", ([
		"amount2"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/ping/obj/gold_hand",
		"amount9"  : 1,
		"file8"    : "/open/scholar/obj/icefan",
		"file6"    : "/open/mon/obj/ghost-legging",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file5"    : "/daemon/class/bonze/puty_pullium",
		"amount5"  : 1,
		"file1"    : "/open/wu/npc/obj/armband",
		"amount1"  : 1,
		"file10"   : "/open/sky/obj/lucky_grasslink",
		"file2"    : "/open/dancer/obj/yuawaist",
		"amount6"  : 1,
		"file4"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount10" : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "owner", "adeyzit" );
	set( "build", 10104 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room289",
	]) );
	set( "long", @LONG
師部大門..小兵回避..除了像一般的營區以外..還多了很多警衛
洽公人員經常會到此..難免都是要上面的批準才能去做的事..如薪餉
問題..人事問題..建制方面的問題..逃兵..上軍事法庭..都要到此來
報到..找上面的人批准..所以皮鞋要擦亮點..銅環要抹亮點..
LONG);
	setup();
	replace_program(ROOM);
}
