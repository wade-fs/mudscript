inherit ROOM;
void create() {
	set( "short", "StarTrek-TOS" );
	set( "owner", "ctx" );
	set( "object", ([
		"amount7"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"file6"    : "/obj/gift/unknowdan",
		"file9"    : "/obj/gift/unknowdan",
		"file3"    : "/obj/gift/unknowdan",
		"amount9"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"file10"   : "/obj/gift/unknowdan",
		"amount1"  : 1,
		"file1"    : "/obj/gift/unknowdan",
		"file4"    : "/obj/gift/unknowdan",
		"amount2"  : 1,
		"file8"    : "/obj/gift/unknowdan",
		"file7"    : "/obj/gift/unknowdan",
		"amount3"  : 1,
		"file5"    : "/obj/gift/unknowdan",
		"amount8"  : 1,
		"file2"    : "/obj/gift/unknowdan",
	]) );
	set( "build", 10329 );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room583",
		"west"      : "/open/clan/ou-cloud-club/room/room547.c",
		"north"     : "/open/clan/ou-cloud-club/room/room546.c",
		"east"      : "/open/clan/ou-cloud-club/room/room548.c",
		"south"     : "/open/clan/ou-cloud-club/room/room549",
		"down"      : "/open/clan/ou-cloud-club/room/room540.c",
	]) );
	set( "long", @LONG
講到StarTrek沒看過的人大概沒幾個吧，這可是相當有名的
一個以星際冒險的故事，而StarTrek-TOS就是他的第一個系列作
品，TOS就是The Original Series的縮寫，裡面寇克船長和他的
搭擋史巴克、史考特等在西元23世紀中與羅慕倫人和克林貢人等
等交手的各種故事，而這部分的故事算是現在中年以上的人最記
憶深刻的了。

LONG);
	setup();
	replace_program(ROOM);
}
