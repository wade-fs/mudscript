inherit ROOM;
void create() {
	set( "short", "龍王丹房" );
	set( "object", ([
		"amount8"  : 1,
		"file1"    : "/open/fire-hole/obj/k-pill",
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount10" : 1,
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount6"  : 1,
		"amount5"  : 1,
		"amount1"  : 300,
		"amount4"  : 1,
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount9"  : 1,
	]) );
	set( "build", 10728 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room359.c",
		"south"     : "/open/clan/13_luck/room/room364",
		"north"     : "/open/clan/13_luck/room/room363.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    火龍幻界的中央處，潛藏著另一頭沉睡的巨龍，人們都稱這隻龍
為火龍之王，要進入龍王窟必須先拿到六光火龍身上的精元，才能夠
抵抗洞窟內的熱度，已有不少的勇者進去後就從未在出來過，聽老一
輩的人說，除非能直接打死睡夢中的龍王，不然一等到龍王驚醒後就
沒有人能活著出來。

LONG);
	setup();
	replace_program(ROOM);
}
