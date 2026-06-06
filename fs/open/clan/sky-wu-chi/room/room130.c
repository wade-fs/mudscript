inherit ROOM;
void create() {
	set( "short", "＊草的裝備室＊" );
	set( "owner", "match" );
	set( "object", ([
		"amount9"  : 1,
		"file2"    : "/obj/gift/shenliwan",
		"amount3"  : 4,
		"amount4"  : 1,
		"amount2"  : 1,
		"file9"    : "/obj/gift/xiandan",
		"amount10" : 1,
		"amount5"  : 1,
		"amount8"  : 1,
		"file6"    : "/open/killer/obj/fire-knife",
		"file1"    : "/open/mogi/castle/obj/lochagem",
		"file4"    : "/open/mon/obj/bear-boots",
		"file5"    : "/obj/gift/unknowdan",
		"amount7"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/dancer/obj/yuawaist",
		"file8"    : "/obj/gift/unknowdan",
		"file3"    : "/open/mogi/castle/obj/sspill",
	]) );
	set( "build", 10035 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room214.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
這裡也是＊草的裝備室＊，裡面存放了很多武器，專門供草出任
務用。草也是專門使用暗器的高手，看到一旁擺放的烈燄手裏劍，這
是他從服部內臟拿偷取到的新暗器，其威力之高，是旁人所無法了解
的，就連草自己也無法知道，因為他到現在也都還沒用過呢！
LONG);
	setup();
	replace_program(ROOM);
}
