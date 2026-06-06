inherit ROOM;
void create() {
	set( "short", "剛強的書房" );
	set( "object", ([
		"amount1"  : 1,
		"amount2"  : 1,
		"amount8"  : 1,
		"file5"    : "/open/capital/obj/4-4",
		"amount6"  : 1,
		"amount3"  : 1,
		"file4"    : "/daemon/class/fighter/armband",
		"amount5"  : 1,
		"file3"    : "/open/mogi/castle/obj/lochagem",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file8"    : "/open/gsword/obj1/sadsword",
		"amount7"  : 1,
		"amount10" : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"amount4"  : 1,
		"file7"    : "/open/gsword/obj1/blosword",
		"file1"    : "/open/firedancer/npc/eq/r_boots",
		"file6"    : "/open/gsword/obj1/blosword",
	]) );
	set( "build", 10842 );
	set( "light_up", 1 );
	set( "owner", "roboii" );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room505",
	]) );
	set( "long", @LONG
    忽然自長沙城之中射出一道白光，映著朝日，直竄達天際～～～
        射日派掌門人－李廣臨死前喟然嘆道～～～
            「啊～～～罷了...想我堂堂一名飛將軍，居然是如此不堪一擊...」
                名動天下的「飛將軍」李廣，竟被『剛強』給一招擊斃於廣義堂內...
LONG);
	setup();
	replace_program(ROOM);
}
