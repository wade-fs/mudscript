inherit ROOM;
void create() {
	set( "short", "煉丹室" );
	set( "object", ([
		"amount2"  : 174,
		"amount10" : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"amount9"  : 1,
		"file3"    : "/open/mogi/castle/obj/sspill",
		"file9"    : "/open/mogi/castle/obj/leave",
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"file5"    : "/open/killer/headkill/obj/world_dag",
		"amount1"  : 35,
		"file2"    : "/open/mon/obj/mon-pill",
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"file6"    : "/open/mogi/castle/obj/fire_book",
		"amount3"  : 9,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 12,
		"file10"   : "/open/mogi/castle/obj/tiger-key",
		"amount5"  : 1,
	]) );
	set( "owner", "blackdog" );
	set( "build", 10076 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room636",
	]) );
	set( "long", @LONG

在狂想，發呆也是有價值的。隨機出現的各式趣聞，只要在線上的人都有機
會得到可以突破自己天賦極限寶物。在練功的同時更可以得到可以增加替身
上限的粉末或碎片。為了使各種丹藥能充分發揮效用，服用的時機是很重要
的，在這裡你可以看到因為時機未到，ＭＯＩ所存放的丹藥。

LONG);
	setup();
	replace_program(ROOM);
}
