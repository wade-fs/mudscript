inherit ROOM;
void create() {
	set( "short", "熊出沒!!注意" );
	set( "owner", "bear" );
	set( "object", ([
		"amount7"  : 1,
		"file1"    : "/open/scholar/obj/icefan",
		"amount8"  : 1,
		"amount5"  : 40,
		"file8"    : "/open/mon/obj/ghost-legging",
		"file3"    : "/open/mogi/castle/obj/sspill",
		"file7"    : "/open/port/obj/wolf_ring",
		"amount4"  : 9,
		"amount6"  : 1,
		"file5"    : "/open/fire-hole/obj/p-pill",
		"file6"    : "/open/mon/obj/ghost-helmet",
		"file9"    : "/daemon/class/bonze/puty_pullium",
		"amount1"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/ping/obj/chilin_legging",
		"amount3"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/mogi/castle/obj/ninepill",
	]) );
	set( "build", 10623 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room441",
	]) );
	set( "long", @LONG
呈現在眼前的是一間十尺見方的店舖，裡頭除了裝滿各
式各樣草藥的櫃子，還有一張小方桌上面放著文房四寶，右
側的牆上掛著幾副山水畫與字畫，深藍色簾幕後面的小房間
傳來搗藥的聲音，隨之傳來帶有辛辣味道的煙霧燻得你眼淚
直流，搞不清楚裡面是在和藥還是做實驗。

LONG);
	setup();
	replace_program(ROOM);
}
