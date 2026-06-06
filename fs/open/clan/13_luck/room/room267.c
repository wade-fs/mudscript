inherit ROOM;
void create() {
	set( "short", "藥房" );
	set( "owner", "pighead" );
	set( "object", ([
		"amount7"  : 1,
		"amount10" : 1,
		"file10"   : "/obj/gift/hobowdan",
		"amount9"  : 1,
		"file8"    : "/daemon/class/fighter/armband",
		"amount2"  : 1,
		"amount8"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mon/obj/ghost-helmet",
		"file7"    : "/open/mogi/castle/obj/lochagem",
	]) );
	set( "build", 10521 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room236.c",
		"west"      : "/open/clan/13_luck/room/room283",
	]) );
	set( "long", @LONG

    進到此房中，地上儘是眷罐罐，其中不乏一些丹藥、中藥、奇花
異草。櫃中也都是各種醫藥書籍參考資料，卓上擺放著研磨工具及各
式的刀具。如果誤食藥物會有嚴重後遺症的。

不然這房間的主人不會幫你醫治 切記

LONG);
	setup();
	replace_program(ROOM);
}
