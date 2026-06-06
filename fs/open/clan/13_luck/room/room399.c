inherit ROOM;
void create() {
	set( "short", "東側走道一" );
	set( "object", ([
		"amount4"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/magic-manor/obj/hwa-je-icer",
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount8"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/obj/hwa-je-icer",
		"file5"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount7"  : 1,
		"file8"    : "/obj/gift/xiandan",
		"amount2"  : 1,
		"file7"    : "/obj/gift/xisuidan",
		"amount3"  : 1,
		"amount10" : 1,
		"file10"   : "/obj/gift/bingtang",
		"amount5"  : 1,
		"amount9"  : 1,
		"file1"    : "/open/magic-manor/obj/hwa-je-icer",
		"file9"    : "/obj/gift/lingzhi",
	]) );
	set( "owner", "roar" );
	set( "build", 10053 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room379.c",
		"east"      : "/open/clan/13_luck/room/room378",
	]) );
	set( "long", @LONG

    眼見十三劍堂就在眼前了，周圍圍繞著許多劍堂的弟子，他們正在巡
視十三劍堂外可疑的份子，若遇到不屬於十三吉祥的人他們可是會大開殺
戒，因為格殺十三吉祥外的份子，可以增加他們的功勳，以便自己在十三
吉祥內獲得更高的職務。

LONG);
	setup();
	replace_program(ROOM);
}
