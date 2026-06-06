inherit ROOM;
void create() {
	set( "short", "綠茶居大廳" );
	set( "object", ([
		"amount3"  : 18,
		"file3"    : "/open/fire-hole/obj/r-pill",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 2,
		"file4"    : "/open/fire-hole/obj/w-pill",
		"amount4"  : 6,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 3,
		"file2"    : "/open/fire-hole/obj/g-pill",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 1,
		"amount8"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10087 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room92",
	]) );
	set( "long", @LONG
一間佈置的古色古香的房間，左右兩旁擺著一列雕功精細的木製
太師椅，椅子旁邊著各放有一盆小盆栽，在你的前方有著一張特
製的桃木椅，一看就知道價值不斐，想必是此居主人的座椅，這
裡便是綠茶居的大廳了。  往東走可以到達前庭，東西兩側則是
通往後院。
LONG);
	setup();
	replace_program(ROOM);
}
