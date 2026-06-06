inherit ROOM;
void create() {
	set( "short", "$RED$『閻羅王』$NOR$的$HIY$收藏地獄$NOR$『$HIC$千墳之水$NOR$』" );
	set( "owner", "neun" );
	set( "object", ([
		"amount1"  : 1,
		"amount2"  : 1,
		"file1"    : "/open/mogi/castle/obj/blood-water",
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
	]) );
	set( "light_up", 1 );
	set( "build", 10286 );
	set( "exits", ([
		"south"     : "/open/clan/hell/room/room30.c",
		"west"      : "/open/clan/hell/room/room27.c",
		"SH"        : "/open/clan/hell/room/room92",
		"up"        : "/open/clan/hell/room/room132",
		"east"      : "/open/clan/hell/room/room22.c",
		"down"      : "/open/clan/hell/room/hall.c",
		"north"     : "/open/clan/hell/room/room28.c",
		"FH"        : "/open/clan/hell/room/room91.c",
	]) );
	set( "long", @LONG
這裡是地府的閻羅王收藏東西的地方,他的鬼子鬼孫們從四處蒐集回來的東西
都會收藏在這裡,由於收藏品實在太多了,所以他收藏的區域不只一間,這裡往四
周延神出去,各有收藏諸般兵器的地方,當然也還有各種神丹妙藥,只要是受到閻
羅王認可的人都可以任意取用,

LONG);
	setup();
	replace_program(ROOM);
}
