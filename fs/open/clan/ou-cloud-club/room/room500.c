inherit ROOM;
void create() {
	set( "short", "3樓公投中心" );
	set( "owner", "ctx" );
	set( "object", ([
		"amount2"  : 1,
		"amount8"  : 1,
		"file1"    : "/obj/gift/xisuidan",
		"amount4"  : 1,
		"file10"   : "/obj/gift/xisuidan",
		"amount10" : 1,
		"file2"    : "/obj/gift/xisuidan",
		"amount9"  : 1,
		"file4"    : "/obj/gift/xisuidan",
		"amount7"  : 1,
		"file9"    : "/obj/gift/xisuidan",
		"file3"    : "/obj/gift/xisuidan",
		"amount5"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"file6"    : "/obj/gift/xisuidan",
		"file7"    : "/obj/gift/xisuidan",
		"file8"    : "/obj/gift/xisuidan",
		"amount3"  : 1,
		"file5"    : "/obj/gift/xisuidan",
	]) );
	set( "build", 10220 );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room495",
		"north"     : "/open/clan/ou-cloud-club/room/room497.c",
		"down"      : "/open/clan/ou-cloud-club/room/room486",
		"south"     : "/open/clan/ou-cloud-club/room/room496.c",
		"east"      : "/open/clan/ou-cloud-club/room/room499.c",
		"west"      : "/open/clan/ou-cloud-club/room/room498.c",
	]) );
	set( "long", @LONG
為了決定要不要在FS建立核電廠, 所以決定在這裡設立投票
中心,不過既然是公投中心,所以什麼東西都可以在這投啦, 舉個
範例來說好了,除了建立核電廠外, 要不要決定全FS的ppl來pk大
陸的人民阿,或者是宣布FS為主權獨立國家阿,都可以, 要投幾票
也可以,重點是,只要有diamond,要投幾票就有幾票。

LONG);
	setup();
	replace_program(ROOM);
}
