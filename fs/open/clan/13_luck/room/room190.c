inherit ROOM;
void create() {
	set( "short", "皮皮的家" );
	set( "object", ([
		"amount3"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/mon/obj/ghost-cloak",
		"file1"    : "/open/wind-rain/obj/sun_red_cloth",
		"file7"    : "/open/ping/obj/ring-2",
		"amount4"  : 1,
		"amount1"  : 1,
		"amount6"  : 1,
		"file8"    : "/open/ping/obj/gold_hand",
		"file3"    : "/daemon/class/blademan/obj/shield",
		"file6"    : "/open/mogi/village/obj/mogi_ring",
		"file4"    : "/open/ping/obj/iceger",
		"amount8"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 9231 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room92",
	]) );
	set( "long", @LONG
這裡就是我是皮皮是我的家，房間的擺設十分的簡單，幾張竹製
的椅子，配上一張竹子製成的方桌，桌上則擺著一盆小盆栽，除
此之外就空蕩蕩的，可謂家徒四璧，想必此處的主人一定沒什麼
搞頭。  從這兒往東走可以回到綠茶園的前庭。
LONG);
	setup();
	replace_program(ROOM);
}
