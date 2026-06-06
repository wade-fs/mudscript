inherit ROOM;
void create() {
	set( "short", "魔王重生" );
	set( "owner", "ctx" );
	set( "object", ([
		"file3"    : "/obj/gift/hobowdan",
		"amount3"  : 1,
		"file2"    : "/obj/gift/hobowdan",
		"file7"    : "/obj/gift/hobowdan",
		"file5"    : "/obj/gift/hobowdan",
		"amount1"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"file6"    : "/obj/gift/hobowdan",
		"file1"    : "/obj/gift/hobowdan",
		"amount6"  : 1,
		"amount7"  : 1,
		"file10"   : "/obj/gift/hobowdan",
		"amount10" : 1,
		"amount2"  : 1,
		"file9"    : "/obj/gift/hobowdan",
		"amount5"  : 1,
		"amount4"  : 1,
		"file4"    : "/obj/gift/hobowdan",
		"file8"    : "/obj/gift/hobowdan",
	]) );
	set( "light_up", 1 );
	set( "build", 10032 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room528",
	]) );
	set( "long", @LONG
一個繼承了魔王之力的人類,在面對了各種不同的勢力下，
堅持的走者屬於自己的道路,也為了自己所愛的女性付出自己的
心力，雖然有者無人能比的魔王之力,但是最想過的生活依然是
跟平常人的生活一樣，能夠過者平常人的生活。

LONG);
	setup();
	replace_program(ROOM);
}
