inherit ROOM;
void create() {
	set( "short", "阿綺的藏寶庫" );
	set( "object", ([
		"amount6"  : 45,
		"file2"    : "/open/mon/obj/mon-pill",
		"file4"    : "/open/mon/obj/mon-pill",
		"file7"    : "/open/mon/obj/mon-pill",
		"amount9"  : 45,
		"amount4"  : 45,
		"file8"    : "/open/mon/obj/mon-pill",
		"file6"    : "/open/mon/obj/mon-pill",
		"file9"    : "/open/mon/obj/mon-pill",
		"file1"    : "/open/mon/obj/mon-pill",
		"file10"   : "/open/mon/obj/mon-pill",
		"amount8"  : 45,
		"amount10" : 45,
		"amount7"  : 45,
		"amount1"  : 45,
		"amount2"  : 45,
	]) );
	set( "owner", "neonn" );
	set( "build", 10016 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room249",
	]) );
	set( "long", @LONG

    這裡是阿綺的藏寶庫，妳抬頭一看不禁一陣暈眩。
金光閃閃、花花綠綠的寶物。有稀世武器，也有一些靈
丹妙藥。嘖嘖，看了好生羨慕。這裡是阿綺的藏寶庫，
妳抬頭一看不禁一陣暈眩。金光閃閃、花花綠綠的寶物
。有稀世武器，也有一些靈丹妙藥。嘖嘖，看了好生羨
慕。

LONG);
	setup();
	replace_program(ROOM);
}
