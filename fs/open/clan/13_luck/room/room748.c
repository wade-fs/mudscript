inherit ROOM;
void create() {
	set( "short", "LEON 千墳水" );
	set( "owner", "adeyzit" );
	set( "object", ([
		"amount6"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount10" : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"amount2"  : 1,
		"amount9"  : 1,
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount4"  : 1,
		"amount3"  : 1,
		"file5"    : "/obj/gift/unknowdan",
		"amount5"  : 1,
	]) );
	set( "build", 10151 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room745",
	]) );
	set( "long", @LONG
之一的機會
這是中了入滅唯一的解藥 沒有這個藥 你只能夠慢慢的等死
來到這邊 或許以為就此得救 誰知只是另一個夢魘的開始 因
為只要一旦喝錯了 你就要馬上跟自己的生命說再見了 看著眼
花撩亂 的千墳水 只能後悔自己不該中毒 不過有希望總比絕
望好 所以你決定發揮樂透精神 跟他拼了 反正生死只是二分
之一的機會
LONG);
	setup();
	replace_program(ROOM);
}
