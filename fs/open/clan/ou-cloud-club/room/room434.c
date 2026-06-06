inherit ROOM;
void create() {
	set( "short", "雨兒的貓診所" );
	set( "owner", "sina" );
	set( "object", ([
		"amount2"  : 30,
		"file8"    : "/open/tendo/obj/book",
		"amount4"  : 1,
		"file1"    : "/open/killer/obj/atman_pill",
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"amount10" : 5,
		"file5"    : "/open/mon/obj/mon-pill",
		"amount8"  : 1,
		"file2"    : "/open/mon/obj/thousand-nectar",
		"amount5"  : 76,
		"amount3"  : 9,
		"file10"   : "/open/fire-hole/obj/r-pill",
		"file6"    : "/obj/gift/lingzhi",
		"file4"    : "/open/dancer/obj/yuawaist",
		"amount1"  : 111,
		"amount6"  : 1,
	]) );
	set( "build", 10492 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room441.c",
		"add"       : "/open/clan/ou-cloud-club/room/room356",
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
