inherit ROOM;
void create() {
	set( "short", "藥丹房二" );
	set( "owner", "panhermes" );
	set( "light_up", 1 );
	set( "object", ([
		"file6"    : "/open/mogi/castle/obj/black-ghost-head",
		"amount4"  : 1,
		"amount3"  : 1,
		"file2"    : "/obj/gift/xiandan",
		"amount2"  : 1,
		"amount9"  : 1,
		"file4"    : "/obj/gift/unknowdan",
		"file3"    : "/obj/gift/hobowdan",
		"amount6"  : 1,
		"file9"    : "/obj/gift/xiandan",
		"file5"    : "/open/mogi/castle/obj/white-ghost-head",
		"amount5"  : 1,
	]) );
	set( "build", 10324 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room176",
	]) );
	set( "long", @LONG
這是機器人一號ㄉ藥丹房,專門收集一些靈丹妙藥,
如能家經驗ㄉ萬年靈芝,如能使人變聰明ㄉ仙丹,
能小補內力ㄉ荷包蛋,能增加靈性ㄉ仙丹.
如能令人亙加強壯ㄉ仙丹.......等等
並希望愛心人士能施捨一些藥丹給他
因為它十分倒楣一輩子都沒撿到過@@
LONG);
	setup();
	replace_program(ROOM);
}
