inherit ROOM;
void create() {
	set( "short", "幻劍書盟" );
	set( "owner", "ctx" );
	set( "object", ([
		"amount3"  : 1,
		"file5"    : "/obj/gift/hobowdan",
		"amount8"  : 1,
		"amount1"  : 1,
		"file3"    : "/obj/gift/hobowdan",
		"amount10" : 1,
		"file6"    : "/obj/gift/hobowdan",
		"amount4"  : 1,
		"amount5"  : 1,
		"file1"    : "/obj/gift/hobowdan",
		"file10"   : "/obj/gift/hobowdan",
		"file9"    : "/obj/gift/hobowdan",
		"amount6"  : 1,
		"file4"    : "/obj/gift/hobowdan",
		"amount9"  : 1,
		"file8"    : "/obj/gift/hobowdan",
		"amount2"  : 1,
		"amount7"  : 1,
		"file7"    : "/obj/gift/hobowdan",
		"file2"    : "/obj/gift/hobowdan",
	]) );
	set( "build", 10029 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room540",
	]) );
	set( "long", @LONG
這邊也是在收藏奇幻文學的網站，而數量也是相當的多，不
同於小說頻道，這邊並沒有提供駐站小說家讓自己的奇幻小說有
上市公開販售的合約，這邊主要祇是提供網路小說的收藏而已，
不過這不影響藏書的收藏量，幾乎所有有出書的有名網路文學作
品都一定會在這邊出現，像是ctx常看的魔法學徒等,這邊幾乎都
可以找到。

LONG);
	setup();
	replace_program(ROOM);
}
