inherit ROOM;
void create() {
	set( "short", "$HIC$含笑半步癲$NOR$" );
	set( "object", ([
		"file9"    : "/open/prayer/obj/boris-hat",
		"amount10" : 1,
		"amount6"  : 1,
		"file1"    : "/obj/stone/suipian",
		"file4"    : "/open/fire-hole/obj/b-pill",
		"file8"    : "/open/capital/obj/king-boots",
		"amount2"  : 36,
		"file6"    : "/open/capital/obj/king-cloak",
		"file2"    : "/obj/stone/powder",
		"amount7"  : 1,
		"amount1"  : 3,
		"file7"    : "/open/capital/obj/king-belt",
		"amount3"  : 1,
		"file3"    : "/open/capital/obj/blade2",
		"amount8"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/capital/obj/king-cloth",
		"amount4"  : 4,
		"file10"   : "/daemon/class/fighter/armband",
		"amount5"  : 1,
	]) );
	set( "owner", "llaa" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room447.c",
		"north"     : "/open/clan/ou-cloud-club/room/room402",
	]) );
	set( "build", 10004 );
	set( "light_up", 1 );
	set( "long", @LONG
含笑半步癲是用蜂蜜、川貝、桔梗、奶沒有防腐劑，除了毒性猛烈之外
，味道還很好吃！吃了含笑半步癲的朋友，顧名思義絕對不能走半步路或是
面露笑容，否則也會全身爆炸而死。實在是居家旅行......殺人滅口.......
必備良藥!!

LONG);
	setup();
	replace_program(ROOM);
}
