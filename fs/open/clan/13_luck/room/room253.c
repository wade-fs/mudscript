inherit ROOM;
void create() {
	set( "short", "『決鬥場』" );
	set( "owner", "poll" );
	set( "object", ([
		"file3"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount5"  : 1,
		"amount9"  : 1,
		"amount10" : 1,
		"amount4"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount1"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount6"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount3"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount8"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount2"  : 1,
	]) );
	set( "build", 10242 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room251",
	]) );
	set( "long", @LONG
你現在正站在決鬥場中，因為這裡是我廖官人特許玩家們一較高低的
地方，所以即使在決鬥中被對方殺死也沒有任何關係，並不會有技能下降
及武術減少的狀況發生，東邊牆角上則懸掛著比賽規則(board)。
在這裡pk...死了不是我的事...以上純屬需構
LONG);
	setup();
	replace_program(ROOM);
}
