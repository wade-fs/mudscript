inherit ROOM;
void create() {
	set( "short", "LEON聚靈丹室" );
	set( "owner", "adeyzit" );
	set( "object", ([
		"amount4"  : 3,
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"file1"    : "/obj/gift/hobowdan",
		"file4"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"amount5"  : 1,
		"file3"    : "/open/mogi/dragon/obj/dragon-head",
		"amount2"  : 1,
		"amount3"  : 1,
		"file2"    : "/open/magic-manor/obj/sun-heart",
		"amount1"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/mogi/dragon/obj/dragon-head",
		"amount7"  : 1,
	]) );
	set( "build", 10844 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room745",
	]) );
	set( "long", @LONG
你一進來馬上就感受到一股靈氣 一種讓人通體舒暢的靈氣只
要用法得當的話 可以為你減少許多傷害 只要運起DREAMWINGS
敵人的傷害都將被阻擋在外 算是一種相當神奇的丹藥 這種丹
藥只有七魔將才有 主人能弄到手實在是不簡單 難怪在外面遍
尋不著 原來都被偷偷收藏到這個神秘的地方 看來這種丹藥已
經絕版了

LONG);
	setup();
	replace_program(ROOM);
}
