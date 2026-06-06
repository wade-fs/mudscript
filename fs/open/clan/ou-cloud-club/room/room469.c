inherit ROOM;
void create() {
	set( "short", "地下一樓管理室" );
	set( "object", ([
		"amount9"  : 1,
		"amount5"  : 1,
		"amount7"  : 1,
		"file7"    : "/obj/gift/hobowdan",
		"amount3"  : 1,
		"file8"    : "/obj/gift/hobowdan",
		"file2"    : "/obj/gift/hobowdan",
		"amount6"  : 1,
		"file6"    : "/obj/gift/hobowdan",
		"amount1"  : 1,
		"amount2"  : 1,
		"file10"   : "/obj/gift/hobowdan",
		"file9"    : "/obj/gift/hobowdan",
		"amount8"  : 1,
		"file5"    : "/obj/gift/hobowdan",
		"file3"    : "/obj/gift/hobowdan",
		"amount10" : 1,
		"amount4"  : 1,
		"file4"    : "/obj/gift/hobowdan",
		"file1"    : "/obj/gift/hobowdan",
	]) );
	set( "build", 11145 );
	set( "owner", "ctx" );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room425.c",
		"east"      : "/open/clan/ou-cloud-club/room/room468.c",
		"south"     : "/open/clan/ou-cloud-club/room/room465",
		"north"     : "/open/clan/ou-cloud-club/room/room467.c",
		"down"      : "/open/clan/ou-cloud-club/room/room506",
		"west"      : "/open/clan/ou-cloud-club/room/room466.c",
	]) );
	set( "long", @LONG
這裡是這棟研究大樓的地下室一樓, 這層樓的研究都是機密
的研究,而這些研究也具有高度危險性,如果沒有通行證請勿亂闖
否則後果自行負責,當然被阿魯巴一頓是一定要的,此外, 因為本
層樓具有高度危險性,所以來此者請先做好個人裝備防護。

LONG);
	setup();
	replace_program(ROOM);
}
