inherit ROOM;
void create() {
	set( "short", "$RED$貓神界 大門$NOR$" );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room14",
		"enter"     : "/open/clan/hell/room/room38",
	]) );
	set( "object", ([
		"file9"    : "/daemon/class/blademan/obj/mkblade",
		"file5"    : "/open/scholar/obj/icefan",
		"amount9"  : 1,
		"amount5"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10057 );
	set( "long", @LONG
    這裡是^(OO)^的地盤，到處瀰漫著怪異的味道........
這裡的掌管者是kalin,他正專心的看著小澤圓的告別座，嘴角還不時流出一絲絲的豬涎。
看來真是讓人嘔吐到最高點!!!!!突然他轉過頭來對你奸笑幾聲，你不禁嚇了一大跳!!!
    這裡是^(OO)^的地盤，到處瀰漫著怪異的味道........
LONG);
	setup();
	replace_program(ROOM);
}
