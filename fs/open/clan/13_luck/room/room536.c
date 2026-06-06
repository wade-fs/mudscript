inherit ROOM;
void create() {
	set( "short", "小武專用房" );
	set( "object", ([
		"amount2"  : 13,
		"amount3"  : 13,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file5"    : "/open/mon/obj/mon-pill",
		"amount10" : 1,
		"amount5"  : 298,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount1"  : 141,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount8"  : 1,
		"amount4"  : 13,
		"file3"    : "/open/fire-hole/obj/r-pill",
		"file4"    : "/open/fire-hole/obj/w-pill",
		"amount6"  : 1,
		"file1"    : "/obj/stone/powder",
		"amount7"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-belt",
		"file2"    : "/obj/stone/suipian",
		"amount9"  : 1,
	]) );
	set( "owner", "hyun" );
	set( "item_desc", ([
		"失戀中" : @ITEM
ITEM,
	]) );
	set( "build", 10012 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room342",
	]) );
	set( "long", @LONG
加油吧..........
加油吧..........
加油吧..........
加油吧..........
加油吧..........
加油吧..........
加油吧..........
加油吧..........
加油吧..........
加油吧..........
加油吧..........
加油吧..........
加油吧..........
加油吧..........
加油吧..........
加油吧..........
加油吧..........
LONG);
	setup();
	replace_program(ROOM);
}
