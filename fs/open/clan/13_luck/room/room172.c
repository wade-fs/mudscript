inherit ROOM;
void create() {
	set( "short", "西偏房" );
	set( "object", ([
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"amount9"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
	]) );
	set( "build", 10050 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room171.c",
		"east"      : "/open/clan/13_luck/room/room139.c",
	]) );
	set( "long", @LONG

    鱗片其功用非常的多，但有一項功用是不被世人所發現的，原來
它是鑄作武器最好的材料之一，有了百煉丹金配上鱗片，在請最好的
師傅，經過七七四十九天的不斷提煉及鍛煉，將可以做出絕世武器，
再用自己的鮮血開封，會使得武器更有靈性。

LONG);
	setup();
	replace_program(ROOM);
}
