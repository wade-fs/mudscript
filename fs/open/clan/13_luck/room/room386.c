inherit ROOM;
void create() {
	set( "short", "殿前大校場三" );
	set( "object", ([
		"amount8"  : 1,
		"amount5"  : 1,
		"amount9"  : 1,
		"file9"    : "/obj/gift/xiandan",
		"file6"    : "/obj/gift/xiandan",
		"amount10" : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"file7"    : "/obj/gift/xiandan",
		"amount7"  : 1,
		"file3"    : "/obj/gift/xiandan",
		"file8"    : "/obj/gift/xiandan",
		"file2"    : "/obj/gift/xiandan",
		"amount6"  : 1,
		"amount1"  : 1,
		"file1"    : "/obj/gift/xiandan",
		"file5"    : "/obj/gift/xiandan",
		"file10"   : "/obj/gift/xiandan",
		"file4"    : "/obj/gift/xiandan",
	]) );
	set( "owner", "roar" );
	set( "build", 14541 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room387",
		"east"      : "/open/clan/13_luck/room/room379.c",
	]) );
	set( "long", @LONG

    這裡是校場的東側，往西則通往校場的中央。因這裡較靠近十三吉祥
四大分堂裡的『十三劍堂』及『十三戰堂』，所以兩堂弟子在此演武的人
數也較其他兩堂為多。校場的東側道路則通往『十三劍堂』。

LONG);
	setup();
	replace_program(ROOM);
}
