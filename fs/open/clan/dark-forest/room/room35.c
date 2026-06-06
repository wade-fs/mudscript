inherit ROOM;
void create() {
	set( "short", "冰淇淋二號" );
	set( "object", ([
		"file2"    : "/open/magic-manor/obj/master_snake_head",
		"file4"    : "/open/magic-manor/obj/master_snake_head",
		"amount5"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/magic-manor/obj/master_snake_head",
		"file1"    : "/open/magic-manor/obj/master_snake_head",
		"amount2"  : 1,
		"file5"    : "/open/magic-manor/obj/master_snake_head",
		"amount3"  : 1,
		"amount4"  : 1,
	]) );
	set( "owner", "mika" );
	set( "build", 10070 );
	set( "exits", ([
		"east"      : "/open/clan/dark-forest/room/room39.c",
		"north"     : "/open/clan/dark-forest/room/room41",
		"south"     : "/open/clan/dark-forest/room/room36.c",
		"west"      : "/open/clan/dark-forest/room/room40.c",
	]) );
	set( "long", @LONG
冰淇淋二號 冰淇淋二號 冰淇淋二號 冰淇淋二號 冰淇淋二號

冰淇淋二號 冰淇淋二號 冰淇淋二號 冰淇淋二號 冰淇淋二號

冰淇淋二號 冰淇淋二號 冰淇淋二號 冰淇淋二號 冰淇淋二號

冰淇淋二號 冰淇淋二號 冰淇淋二號 冰淇淋二號 冰淇淋二號

冰淇淋二號 冰淇淋二號 冰淇淋二號 冰淇淋二號 冰淇淋二號
LONG);
	setup();
	replace_program(ROOM);
}
