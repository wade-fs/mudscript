inherit ROOM;
void create() {
	set( "short", "藥丹房" );
	set( "owner", "cong" );
	set( "object", ([
		"amount8"  : 1,
		"file6"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount7"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file7"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file8"    : "/daemon/class/blademan/obj/skykey",
		"amount3"  : 1,
		"amount4"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount6"  : 1,
		"file1"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file5"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount1"  : 1,
		"file4"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount5"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10830 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room175.c",
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
