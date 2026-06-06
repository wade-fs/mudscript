inherit ROOM;
void create() {
	set( "short", "煉丹房" );
	set( "owner", "matrix" );
	set( "object", ([
		"file4"    : "/open/mon/obj/ghost-helmet",
		"file8"    : "/open/gsword/obj/yuskirt",
		"amount8"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/wu/npc/obj/armband",
		"amount5"  : 1,
		"file2"    : "/open/mon/obj/ghost-cloak",
		"file9"    : "/open/gsword/obj/yubracelet",
		"amount1"  : 1,
		"file1"    : "/open/mon/obj/ghost-claw",
		"amount7"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/ping/obj/iceger",
		"amount9"  : 1,
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount2"  : 1,
	]) );
	set( "build", 12937 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room76",
	]) );
	set( "long", @LONG
走進室內, 芳香撲鼻而來, 妳定了定神遊目四顧, 原來這處是丹藥房, 

就在妳收括此處時, 眼前的紫金色丹藥吸引了妳的注意.... 哇哩ooxx.

.....這不是江湖中人口耳相傳的可增強一甲子功力的九轉金丹? 怎會

這麼多?? 哇哈哈, 天助我也, 老弟我就全部捕走啦...哈哈哈... 

 九轉熊蛇丸? 生生造化丹? 全收括來當糖果吃好了 你又邪笑了起來.
LONG);
	setup();
	replace_program(ROOM);
}
