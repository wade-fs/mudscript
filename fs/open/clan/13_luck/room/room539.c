inherit ROOM;
void create() {
	set( "short", "地窖" );
	set( "object", ([
		"file4"    : "/open/magic-manor/obj/lunar-heart",
		"file6"    : "/open/magic-manor/obj/lunar-heart",
		"file2"    : "/open/magic-manor/obj/lunar-heart",
		"file3"    : "/open/magic-manor/obj/lunar-heart",
		"amount7"  : 1,
		"amount10" : 1,
		"amount5"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/magic-manor/obj/lunar-heart",
		"amount8"  : 1,
		"amount1"  : 1,
		"file10"   : "/open/center/obj/mechoufen-head",
		"file5"    : "/open/magic-manor/obj/lunar-heart",
		"file1"    : "/open/magic-manor/obj/lunar-heart",
		"file9"    : "/open/center/obj/mechoufen-head",
		"file8"    : "/open/center/obj/mechoufen-head",
		"amount9"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
	]) );
	set( "owner", "zmud" );
	set( "build", 10087 );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/13_luck/room/room354.c",
		"west"      : "/open/clan/13_luck/room/room538",
	]) );
	set( "long", @LONG

    在這各密閉空間裡你比發現遠遠的還大,但是這裡卻推滿了滿滿的雜物,你仔細一看發現這些
雜物,竟然是一些了不得的東西,像黃金甲龍的鱗片,火鳳凰的羽毛,玄武的硬殼,林林種種的寶物
就推砌在這裡,沒想到這裡竟然還有書櫃,書櫃裡面盡然是一本本的當今名揚四海的武功密笈,讓裡
想在這裡好好的看玩所有武功的奧秘.

LONG);
	setup();
	replace_program(ROOM);
}
