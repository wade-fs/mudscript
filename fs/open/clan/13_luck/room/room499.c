inherit ROOM;
void create() {
	set( "short", "廣場" );
	set( "owner", "mill" );
	set( "object", ([
		"file9"    : "/obj/gift/xiandan",
		"amount8"  : 1,
		"file3"    : "/obj/gift/xisuidan",
		"file8"    : "/obj/gift/xisuidan",
		"amount4"  : 1,
		"file7"    : "/obj/gift/unknowdan",
		"file6"    : "/obj/gift/lingzhi",
		"amount9"  : 1,
		"amount6"  : 1,
		"file4"    : "/obj/gift/hobowdan",
		"amount3"  : 1,
		"amount7"  : 1,
	]) );
	set( "build", 10153 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room500",
		"north"     : "/open/clan/13_luck/room/room498",
	]) );
	set( "long", @LONG

　　進入門內之後，見到一個廣場，有不少人在此練武強身，廣場周
圍還種植了許多的花草樹木，使得廣場感覺起來不會太過於嚴肅，廣
場四周圍還放了不少的兵器，以提供練武的人使用。烈陽下，刀劍反
射陽光，只見四處刀光劍影，十分的刺眼。

LONG);
	setup();
	replace_program(ROOM);
}
