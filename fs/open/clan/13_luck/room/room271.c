inherit ROOM;
void create() {
	set( "short", "冰雪神戒室" );
	set( "object", ([
		"file2"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount2"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount5"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount3"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount1"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount6"  : 1,
	]) );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room278",
		"south"     : "/open/clan/13_luck/room/room300.c",
	]) );
	set( "build", 10224 );
	set( "light_up", 1 );
	set( "long", @LONG

    傳說中會把人冰住的神戒，可以讓人短暫時間無法移動，此戒乃在
平南稅官的手中，常常會有人為了神戒，銀行少一半的錢也無所謂，為
了是這一只的神戒，在以後打怪物更是無往不利，使玩家信心大增，以
後的一代大俠願望更是信心滿滿。

LONG);
	setup();
	replace_program(ROOM);
}
