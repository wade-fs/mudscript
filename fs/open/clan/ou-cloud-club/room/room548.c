inherit ROOM;
void create() {
	set( "short", "StarTrek-VOY" );
	set( "owner", "ctx" );
	set( "object", ([
		"file4"    : "/obj/gift/xiandan",
		"file8"    : "/obj/gift/xiandan",
		"amount8"  : 1,
		"file6"    : "/obj/gift/xiandan",
		"amount10" : 1,
		"file1"    : "/obj/gift/xiandan",
		"amount5"  : 1,
		"file7"    : "/obj/gift/xiandan",
		"amount6"  : 1,
		"file9"    : "/obj/gift/xiandan",
		"file2"    : "/obj/gift/xiandan",
		"file10"   : "/open/gsword/obj1/bbladeball",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"file3"    : "/obj/gift/xiandan",
		"amount9"  : 1,
		"amount7"  : 1,
		"file5"    : "/obj/gift/xiandan",
		"amount3"  : 1,
	]) );
	set( "build", 12861 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room545",
	]) );
	set( "long", @LONG
StarTrek的第四部系列作品，VOY即劇情中船艦Voyager的縮
寫，其故事年代約與TNG、DS9相近(稍晚幾年)，故事內容講到珍
葳艦長率領船員執行聯邦任務時(緝拿馬奇游擊隊員)，碰到一不
可之事件而整船人被丟在距離聯邦領域有數萬光年的不知名地帶
然後開始回家的種種故事。

LONG);
	setup();
	replace_program(ROOM);
}
