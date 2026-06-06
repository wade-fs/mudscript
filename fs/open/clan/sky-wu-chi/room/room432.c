inherit ROOM;
void create() {
	set( "short", "暗室" );
	set( "owner", "match" );
	set( "object", ([
		"file4"    : "/open/killer/weapon/k_boot3",
		"amount9"  : 1,
		"file9"    : "/obj/gift/shenliwan",
		"amount1"  : 1,
		"file3"    : "/open/mon/obj/ghost-cloak",
		"amount5"  : 1,
		"file6"    : "/open/main/room/sp/stone",
		"amount4"  : 1,
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"amount10" : 1,
		"amount3"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"file1"    : "/open/killer/weapon/k_cloth3",
		"file5"    : "/open/mon/obj/ghost-helmet",
		"amount7"  : 1,
		"amount6"  : 1,
		"amount8"  : 1,
		"file10"   : "/open/main/room/sp/stone",
		"amount2"  : 1,
		"file8"    : "/obj/gift/xisuidan",
	]) );
	set( "build", 17913 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room214",
		"west"      : "/open/clan/sky-wu-chi/room/room430.c",
		"east"      : "/open/clan/sky-wu-chi/room/room431.c",
	]) );
	set( "long", @LONG
這一間是草的暗室，旁邊兩間的房間可以通到許多的地方，由於
屋子處於ξ時空分隔ξ的地點，所以會跑到哪個地方是沒有人會知道
的，只有當草自己念出正確的咒語，才會通往正確的地方，若是笨蛋
闖入，你可能會掉到茅坑也不一定。。。
LONG);
	setup();
	replace_program(ROOM);
}
