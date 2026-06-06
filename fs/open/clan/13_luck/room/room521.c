inherit ROOM;
void create() {
	set( "short", "東長廊" );
	set( "object", ([
		"amount5"  : 1,
		"file10"   : "/open/mon/obj/ghost-claw",
		"amount9"  : 1,
		"file2"    : "/open/mon/obj/ghost-claw",
		"file6"    : "/open/mon/obj/ghost-claw",
		"amount6"  : 1,
		"file9"    : "/open/mon/obj/ghost-claw",
		"amount7"  : 1,
		"file5"    : "/open/mon/obj/ghost-claw",
		"amount2"  : 1,
		"file7"    : "/open/mon/obj/ghost-claw",
		"amount10" : 1,
	]) );
	set( "owner", "aaabc" );
	set( "build", 12081 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room520",
		"north"     : "/open/clan/13_luck/room/room522",
	]) );
	set( "long", @LONG
你現在正在東長廊上，橡木所鋪的地板，感覺起來一塵不染。陽光
由窗上灑落了下來，使得長廊特別的明亮。兩旁還掛了許多的字畫，全
是名家手筆，還真令你想細細琢摹。不忍離去呢。跟四周的強烈殺氣成
了一個強烈的對比，仿佛來到了帶著天堂的環境，但是是地獄的地方。

LONG);
	setup();
	replace_program(ROOM);
}
