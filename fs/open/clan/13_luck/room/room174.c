inherit ROOM;
void create() {
	set( "short", "北偏房" );
	set( "object", ([
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount5"  : 1,
		"amount7"  : 1,
		"amount2"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"amount3"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"amount4"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10476 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room139.c",
		"north"     : "/open/clan/13_luck/room/room173",
	]) );
	set( "long", @LONG

    這一片片的鱗片，內藏著不可思議的魔力，聽老一輩長老們說著
如果將自己的內勁灌入鱗片中，將會有奇特的情形發生，至於會發生
什麼事，長老們一口同聲的說，有機會自己去體驗看看，於是你就拿
起鱗片，將內勁灌入鱗片中，一陣亮光攏照著你，當你眼睛張開....

LONG);
	setup();
	replace_program(ROOM);
}
