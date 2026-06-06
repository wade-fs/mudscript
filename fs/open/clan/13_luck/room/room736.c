inherit ROOM;
void create() {
	set( "short", "明日丹藥房" );
	set( "owner", "tomorrow" );
	set( "object", ([
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 500,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"file2"    : "/open/killer/obj/atman_pill",
		"amount8"  : 500,
		"file6"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file4"    : "/open/mogi/castle/obj/sspill",
		"file3"    : "/open/mon/obj/mon-pill",
		"amount6"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"amount4"  : 102,
		"amount3"  : 500,
		"amount1"  : 500,
		"file8"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount2"  : 33520,
		"file1"    : "/open/ping/obj/poison_pill",
	]) );
	set( "build", 10142 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room751",
		"west"      : "/open/clan/13_luck/room/room735.c",
		"east"      : "/open/clan/13_luck/room/room734.c",
		"north"     : "/open/clan/13_luck/room/room737.c",
		"out"       : "/open/clan/13_luck/room/room726.c",
	]) );
	set( "long", @LONG
    
    此地是tomorrow的丹藥房  主要是存放未來需要的丹藥
像是六色龍精元  生生造化丹  九轉熊蛇丸  千年靈芝仙丹
都是一些稀有的丹藥  這些都是tomorrow南征北討得來的 
不禁心想  有了這些丹藥  再頑強的敵人也不是對手 
對tomorrow的敬畏之心油然而升


LONG);
	setup();
	replace_program(ROOM);
}
