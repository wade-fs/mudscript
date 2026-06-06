inherit ROOM;
void create() {
	set( "short", "冒險者天堂" );
	set( "owner", "ctx" );
	set( "object", ([
		"amount8"  : 1,
		"amount9"  : 1,
		"file10"   : "/obj/gift/xiandan",
		"file2"    : "/obj/gift/xiandan",
		"file5"    : "/obj/gift/xiandan",
		"amount6"  : 1,
		"file4"    : "/obj/gift/xiandan",
		"amount4"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"amount1"  : 1,
		"file3"    : "/obj/gift/xiandan",
		"file1"    : "/obj/gift/xiandan",
		"amount3"  : 1,
		"file6"    : "/obj/gift/xiandan",
		"amount7"  : 1,
		"file7"    : "/obj/gift/xiandan",
		"amount5"  : 1,
		"file8"    : "/obj/gift/xiandan",
		"file9"    : "/obj/gift/xiandan",
	]) );
	set( "build", 10093 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room540",
	]) );
	set( "long", @LONG
這裡算是新興的奇幻文學網站，比起小說頻道、幻劍書盟、
玄幻書殿等等來說，看過那些網站的讀者大概不會想逛這各站台
因為這裡算是比較新的網路小說站台,不過ctx本人一開始也是由
這個站台開始拓展視野到小說頻道等等相當有名的網站的，而這
邊有時也會發現一些不錯的小說的，所以瀏覽這邊也是一個不錯
的選擇。

LONG);
	setup();
	replace_program(ROOM);
}
