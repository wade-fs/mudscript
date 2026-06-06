inherit ROOM;
void create() {
	set( "short", "泠的水晶宮" );
	set( "owner", "poiiiiop" );
	set( "object", ([
		"amount10" : 1,
		"file10"   : "/open/magic-manor/obj/golden-ball",
		"amount3"  : 3,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/ping/obj/poison_pill",
		"amount1"  : 22,
		"amount9"  : 1,
		"amount2"  : 50,
		"file2"    : "/open/killer/obj/bellstar",
		"file3"    : "/open/magic-manor/ghost/obj/trigram-pill",
	]) );
	set( "build", 10089 );
	set( "exits", ([
		"up"        : "/open/clan/sky-wu-chi/room/room407",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"east"      : "/open/clan/sky-wu-chi/room/room380.c",
	]) );
	set( "long", @LONG

這是一座水晶宮；在遠古的傳說之中，
水晶宮為龍王的居所，而龍王在中國神
話裡是掌管五湖四海的水神；所以，水
晶宮又稱為【龍宮】。傳說中龍是最喜
歡亮晶晶的東西。所以在這裡收藏許多
的寶物，更堆滿了多種不知名的書籍。

LONG);
	setup();
	replace_program(ROOM);
}
