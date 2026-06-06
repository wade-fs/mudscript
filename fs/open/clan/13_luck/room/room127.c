inherit ROOM;
void create() {
	set( "short", "小豬頭的大廳" );
	set( "owner", "pighead" );
	set( "object", ([
		"amount6"  : 1,
		"file7"    : "/open/killer/obj/k_ring",
		"file5"    : "/open/mogi/castle/obj/lochagem",
		"file3"    : "/open/gblade/obj/sa-head",
		"file1"    : "/open/port/obj/wolf_ring",
		"file6"    : "/open/magic-manor/obj/magic-sign",
		"file2"    : "/open/fire-hole/obj/k-pill",
		"amount5"  : 1,
		"amount3"  : 1,
		"amount8"  : 3,
		"amount1"  : 1,
		"amount9"  : 1,
		"amount7"  : 1,
		"amount10" : 1,
		"file9"    : "/open/ping/obj/poison_pill",
		"file8"    : "/open/mogi/castle/obj/sspill",
		"file4"    : "/daemon/class/fighter/armband",
		"file10"   : "/open/killer/headkill/obj/world_dag",
		"amount4"  : 1,
		"amount2"  : 20,
	]) );
	set( "light_up", 1 );
	set( "build", 10467 );
	set( "exits", ([
		"up"        : "/open/clan/13_luck/room/room412",
		"east"      : "/open/clan/13_luck/room/room295.c",
		"north"     : "/open/clan/13_luck/room/room296.c",
		"out"       : "/open/clan/13_luck/room/room93.c",
		"west"      : "/open/clan/13_luck/room/room294.c",
		"south"     : "/open/clan/13_luck/room/room293",
	]) );
	set( "long", @LONG

    這裡是可愛小豬頭的大廳，以這邊為中心，分別有東西南北廂房
往東邊是東箱房，主要是儲存一般的防具，為平常戰鬥之用，往西邊
是西廂房，主要是儲存一般的武器，為平常戰鬥之用，往北邊是北廂
房，主要是儲存各式各樣的藥品，往南邊是南廂房，主要是儲存一些
雜七雜八的物品。從這邊往上是小豬頭休息的地方。

LONG);
	setup();
	replace_program(ROOM);
}
