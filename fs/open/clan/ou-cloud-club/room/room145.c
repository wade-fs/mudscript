inherit ROOM;
void create() {
	set( "short", "$HIC$練武場$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"file3"    : "/obj/gift/xiandan",
		"file7"    : "/daemon/class/fighter/armband",
		"amount5"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/dancer/obj/yuawaist",
		"amount10" : 185,
		"file1"    : "/open/capital/guard/gring",
		"amount7"  : 1,
		"file9"    : "/open/mon/obj/ghost-cloak",
		"file10"   : "/open/ping/obj/poison_pill",
		"amount9"  : 1,
		"file8"    : "/open/killer/obj/fire-knife",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/prayer/obj/boris-cloth",
		"file5"    : "/open/scholar/obj/icefan",
	]) );
	set( "owner", "enter" );
	set( "light_up", 1 );
	set( "build", 10933 );
	set( "exits", ([
		"enter"     : "/open/clan/ou-cloud-club/room/room146",
		"down"      : "/open/clan/ou-cloud-club/room/room144.c",
	]) );
	set( "long", @LONG
此處是幫主用來鍛鍊武學之地，地處封劍閣之上方，據聞此間
關有一火龍窟中的猛獸，因其受封劍閣內的十把神兵劍芒所制，一
直無法逃出此間，而幫主也常常拿此猛獸來練習武學，因幫主不喜
有旁人觀看，故此間一直被禁止任何人能進入的．

LONG);
	setup();
	replace_program(ROOM);
}
