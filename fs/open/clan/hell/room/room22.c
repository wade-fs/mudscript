inherit ROOM;
void create() {
	set( "short", "$HIY$魔龍鱗$HIW$之界$NOR$PART1" );
	set( "owner", "neun" );
	set( "object", ([
		"file8"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"amount9"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "light_up", 1 );
	set( "build", 10720 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room56.c",
		"west"      : "/open/clan/hell/room/room23.c",
	]) );
	set( "long", @LONG
當幫中得到魔龍鱗片的時候,幫主會將之存放於此處,除了紀念殺死甲龍的功績
之外,也可以再情況緊急的時候,將幫眾們送到魔界,除此之外,偶而還可以拿來當做
製造武器之用,你仔細一看,發覺這裡四周都是閃閃發亮的鱗片,輝映著地獄的火光
不禁讓你對地府的實力重新估計

LONG);
	setup();
	replace_program(ROOM);
}
