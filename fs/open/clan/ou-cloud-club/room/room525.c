inherit ROOM;
void create() {
	set( "short", "我是大法師" );
	set( "owner", "ctx" );
	set( "light_up", 1 );
	set( "object", ([
		"file3"    : "/obj/gift/xiandan",
		"file4"    : "/obj/gift/xiandan",
		"amount4"  : 1,
		"file6"    : "/obj/gift/xiandan",
		"file7"    : "/obj/gift/xiandan",
		"amount2"  : 1,
		"file9"    : "/obj/gift/xiandan",
		"amount9"  : 1,
		"amount10" : 1,
		"file8"    : "/obj/gift/xiandan",
		"amount3"  : 1,
		"file1"    : "/obj/gift/xiandan",
		"amount5"  : 1,
		"amount7"  : 1,
		"file5"    : "/obj/gift/xiandan",
		"file10"   : "/obj/gift/xiandan",
		"file2"    : "/obj/gift/xiandan",
		"amount6"  : 1,
		"amount8"  : 1,
		"amount1"  : 1,
	]) );
	set( "build", 10232 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room517",
	]) );
	set( "long", @LONG
在一個魔法與劍的異世界裏,一個平凡的高中生吳來縱橫馳
騁,收服強大的魔獸、征服頂級的人族、神族、魔族、妖精以及
精靈等等美女,「魔神王」的名字萬古流芳，但面臨著魔界之王
和創世之神前，他該何如何尋找自己的道路呢？

LONG);
	setup();
	replace_program(ROOM);
}
