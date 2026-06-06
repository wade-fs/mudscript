inherit ROOM;
void create() {
	set( "short", "冰淇淋四號" );
	set( "object", ([
		"file8"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount4"  : 1,
		"amount1"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount7"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount2"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount5"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
	]) );
	set( "build", 10270 );
	set( "owner", "mika" );
	set( "exits", ([
		"east"      : "/open/clan/dark-forest/room/room45.c",
		"north"     : "/open/clan/dark-forest/room/room47",
		"south"     : "/open/clan/dark-forest/room/room41.c",
		"west"      : "/open/clan/dark-forest/room/room46.c",
	]) );
	set( "long", @LONG
冰淇淋四號冰淇淋四號冰淇淋四號冰淇淋四號冰淇淋四號
    冰淇淋四號冰淇淋四號冰淇淋四號冰淇淋四號冰淇淋四號
    冰淇淋四號冰淇淋四號冰淇淋四號冰淇淋四號冰淇淋四號
    冰淇淋四號冰淇淋四號冰淇淋四號冰淇淋四號冰淇淋四號
    冰淇淋四號冰淇淋四號冰淇淋四號冰淇淋四號冰淇淋四號
    冰淇淋四號冰淇淋四號冰淇淋四號冰淇淋四號冰淇淋四號
    冰淇淋四號冰淇淋四號冰淇淋四號冰淇淋四號冰淇淋四號
LONG);
	setup();
	replace_program(ROOM);
}
