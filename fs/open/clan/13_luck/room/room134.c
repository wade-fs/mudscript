inherit ROOM;
void create() {
	set( "short", "紅塵笑" );
	set( "owner", "mill" );
	set( "object", ([
		"amount8"  : 2,
		"file2"    : "/open/mon/obj/ghost-helmet",
		"amount1"  : 1,
		"file6"    : "/open/sky/obj/lucky_grasslink",
		"amount2"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file7"    : "/open/capital/guard/gring",
		"file4"    : "/open/mon/obj/ghost-claw",
		"file5"    : "/daemon/class/bonze/puty_pullium",
		"amount4"  : 1,
		"file8"    : "/open/mogi/castle/obj/sspill",
		"file1"    : "/open/mon/obj/ghost-legging",
		"amount7"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 10741 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room131.c",
		"west"      : "/open/clan/13_luck/room/room132.c",
		"north"     : "/open/clan/13_luck/room/room130.c",
		"east"      : "/open/clan/13_luck/room/room133.c",
	]) );
	set( "long", @LONG

    在這裡四周佈滿了江湖的味道，兵器呈四面，武功秘籍現八方，聽說
十三幫主在當初以後起新秀的身份，以絕世高超的武藝打倒了一些老前輩
，更得以將武林前輩的傳家之寶，跟敝家絕傳給一一心乾情願的交給他，
或許當今武林能打倒他的寮寮無幾，他便是武林歌頌的奇人 創世狂人 。

LONG);
	setup();
	replace_program(ROOM);
}
