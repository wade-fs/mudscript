inherit ROOM;
void create() {
	set( "short", "龍鱗廳大門" );
	set( "object", ([
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file8"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
	]) );
	set( "build", 10335 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room136.c",
		"enter"     : "/open/clan/13_luck/room/room139",
	]) );
	set( "long", @LONG

　　一來到這即看見大門上方的那個金色牌匾，不時發出耀眼的金光
，吸引著眾人的目光。人人都已為那牌匾是以純金打造而成的，其實
不然，它的來歷可不簡單。原來那是取自於魔界的黃金甲龍身上的鱗
片所鑄成，價值連城的稀世珍寶。 

LONG);
	setup();
	replace_program(ROOM);
}
