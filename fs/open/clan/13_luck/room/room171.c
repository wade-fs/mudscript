inherit ROOM;
void create() {
	set( "short", "西內偏房" );
	set( "object", ([
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"amount10" : 1,
		"amount4"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
	]) );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room172",
	]) );
	set( "build", 10470 );
	set( "light_up", 1 );
	set( "long", @LONG

    鱗片其功用非常的多，但有一項功用是不被世人所發現的，原來
它是鑄作武器最好的材料之一，有了百煉丹金配上鱗片，在請最好的
師傅，經過七七四十九天的不斷提煉及鍛煉，將可以做出絕世武器，
再用自己的鮮血開封，會使得武器更有靈性。

LONG);
	setup();
	replace_program(ROOM);
}
