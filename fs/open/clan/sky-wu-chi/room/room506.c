inherit ROOM;
void create() {
	set( "short", "nanahara專用" );
	set( "owner", "nanahara" );
	set( "object", ([
		"file4"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount1"  : 1,
		"file8"    : "/open/ping/obj/gold_hand",
		"amount7"  : 3,
		"file7"    : "/obj/stone/powder",
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount4"  : 1,
		"amount5"  : 2,
		"file2"    : "/open/wu/obj/ywboots",
		"amount8"  : 1,
		"file6"    : "/daemon/class/blademan/obj/shield",
		"amount10" : 1,
		"file3"    : "/obj/stone/jiao",
		"amount3"  : 5,
		"file9"    : "/open/scholar/obj/icefan",
		"amount2"  : 1,
		"amount6"  : 1,
		"file10"   : "/open/snow/obj/figring",
		"file5"    : "/obj/stone/suipian",
		"amount9"  : 1,
	]) );
	set( "build", 10040 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"west"      : "/open/clan/sky-wu-chi/room/room657",
	]) );
	set( "long", @LONG

一來這裡，一股異常怪異的味道衝進鼻子裡，衝擊著味覺神經。
淩亂的環境中充斥各種奇怪的東西，仔細一看，哇靠....最新的
仿真人充氣娃娃竟然就放在房間的一角，而其中一個還是依稀看
到有人在上面做著令人不堪入目的動作。

LONG);
	setup();
	replace_program(ROOM);
}
