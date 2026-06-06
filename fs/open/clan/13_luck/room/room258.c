inherit ROOM;
void create() {
	set( "short", "『桃築門口』" );
	set( "owner", "mill" );
	set( "object", ([
		"file5"    : "/open/mon/obj/ghost-legging",
		"file10"   : "/open/ping/obj/fu_weapon",
		"file3"    : "/open/killer/memory/static",
		"amount1"  : 1,
		"amount7"  : 1,
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"file9"    : "/open/scholar/obj/icefan",
		"file7"    : "/daemon/class/blademan/obj/shield",
		"file1"    : "/open/gsword/obj/yuskirt",
		"file8"    : "/open/killer/obj/k_ring",
		"amount9"  : 1,
		"file2"    : "/open/mon/obj/ghost-cloak",
		"amount8"  : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"file6"    : "/open/mon/obj/ghost-helmet",
		"amount10" : 1,
	]) );
	set( "build", 11259 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room257",
		"north"     : "/open/clan/13_luck/room/room259.c",
	]) );
	set( "long", @LONG
走到桃雲小築的門口，看到四周綠油油的一片綠意，不由得佩服起隱居的兩
位居士。四面自給自足的農地，不禁想到有句詩是這樣講的︰「鋤禾日當午，汗
滴禾下土；誰知盤中飧，粒粒皆辛苦。」想到這裡，你不由得升起感激的心理，
真想快點進到桃雲小築裡面看看是哪兩位居士在此居住。
LONG);
	setup();
	replace_program(ROOM);
}
