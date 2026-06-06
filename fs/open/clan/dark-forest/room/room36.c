inherit ROOM;
void create() {
	set( "short", "冰淇淋一號" );
	set( "object", ([
		"file2"    : "/open/tendo/obj/chaosbelt",
		"file6"    : "/obj/gift/lingzhi",
		"file5"    : "/daemon/class/blademan/obj/shield",
		"file3"    : "/obj/stone/powder",
		"amount6"  : 1,
		"amount8"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file1"    : "/obj/stone/suipian",
		"amount3"  : 3,
		"amount2"  : 1,
		"amount9"  : 1,
		"amount7"  : 1,
		"amount5"  : 1,
		"file9"    : "/open/mogi/castle/obj/lochagem",
		"amount4"  : 1,
		"amount1"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"file8"    : "/open/wind-rain/obj/sun_red_cloth",
		"file4"    : "/open/wu/obj/figring",
	]) );
	set( "owner", "mika" );
	set( "build", 10108 );
	set( "exits", ([
		"east"      : "/open/clan/dark-forest/room/room38.c",
		"west"      : "/open/clan/dark-forest/room/room34",
		"north"     : "/open/clan/dark-forest/room/room35.c",
		"south"     : "/open/clan/dark-forest/room/room4.c",
	]) );
	set( "long", @LONG
冰淇淋一號 冰淇淋一號 冰淇淋一號 冰淇淋一號 冰淇淋一號

冰淇淋一號 冰淇淋一號 冰淇淋一號 冰淇淋一號 冰淇淋一號

冰淇淋一號 冰淇淋一號 冰淇淋一號 冰淇淋一號 冰淇淋一號

冰淇淋一號 冰淇淋一號 冰淇淋一號 冰淇淋一號 冰淇淋一號

冰淇淋一號 冰淇淋一號 冰淇淋一號 冰淇淋一號 冰淇淋一號
LONG);
	setup();
	replace_program(ROOM);
}
