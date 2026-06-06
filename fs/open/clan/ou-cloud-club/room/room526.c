inherit ROOM;
void create() {
	set( "short", "魔女天嬌" );
	set( "object", ([
		"file6"    : "/obj/gift/hobowdan",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"amount9"  : 1,
		"file7"    : "/obj/gift/hobowdan",
		"amount10" : 1,
		"file2"    : "/obj/gift/hobowdan",
		"file4"    : "/obj/gift/hobowdan",
		"file8"    : "/obj/gift/hobowdan",
		"file5"    : "/obj/gift/hobowdan",
		"amount8"  : 1,
		"file9"    : "/obj/gift/hobowdan",
		"file1"    : "/obj/gift/hobowdan",
		"file10"   : "/obj/gift/hobowdan",
		"amount3"  : 1,
		"amount6"  : 1,
		"file3"    : "/obj/gift/hobowdan",
		"amount1"  : 1,
		"amount5"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10012 );
	set( "owner", "ctx" );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room517",
	]) );
	set( "long", @LONG
一個背景故事在明朝的故事， 天熙宮的大宮主因母親早死
而性情大變乃至妄想以女色控制整各江湖,而男主角羅開因緣際
會巧遇天熙宮前任宮主，並傳授主角一身武功,且委託主角矯正
其女兒荼毒江湖的行為,中間並牽脫出明朝政府也有控制江湖各
派的野心。

LONG);
	setup();
	replace_program(ROOM);
}
