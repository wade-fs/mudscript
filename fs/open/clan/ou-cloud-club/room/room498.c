inherit ROOM;
void create() {
	set( "short", "FS開發金控董事長室" );
	set( "object", ([
		"amount3"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
		"file5"    : "/obj/gift/xiandan",
		"file8"    : "/obj/gift/xiandan",
		"file3"    : "/obj/gift/xiandan",
		"amount4"  : 1,
		"amount2"  : 1,
		"file6"    : "/obj/gift/xiandan",
		"amount5"  : 1,
		"file1"    : "/obj/gift/xiandan",
		"file10"   : "/obj/gift/xiandan",
		"file9"    : "/obj/gift/xiandan",
		"amount9"  : 1,
		"amount1"  : 1,
		"file7"    : "/obj/gift/xiandan",
		"file2"    : "/obj/gift/xiandan",
		"amount7"  : 1,
		"file4"    : "/obj/gift/xiandan",
	]) );
	set( "owner", "ctx" );
	set( "build", 11933 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room500",
	]) );
	set( "long", @LONG
這就是全FS最有勢力的金控中心的董事長辦公室了, 雖然最
近金控中心出了點事情,所以這間辦公室的主人變了一個,雖然說
變了個主人應該不是啥咪重點,不過還是有值得一提的,那就是現
在這個主人算是美女,又多金,推薦想上的快上喔,可以少奮鬥100
00年吧,從恐龍時代到現在都不用奮鬥了。

LONG);
	setup();
	replace_program(ROOM);
}
