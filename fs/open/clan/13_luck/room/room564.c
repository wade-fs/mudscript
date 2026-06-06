inherit ROOM;
void create() {
	set( "short", "練武場" );
	set( "owner", "roarii" );
	set( "object", ([
		"amount3"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"amount7"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10029 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room565",
		"north"     : "/open/clan/13_luck/room/room563",
	]) );
	set( "long", @LONG
你現在站在東邊的大練武場中，在這裡練武的弟子們武功並不
是很好，正在練習所有武功之中最為基本的沉馬，或許是只是剛加
入不久吧。場地中央有一名全身透出一股英悍之氣的彪形大漢在教
導弟子們。
LONG);
	setup();
	replace_program(ROOM);
}
