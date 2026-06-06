inherit ROOM;
void create() {
	set( "short", "西練武場" );
	set( "owner", "roarii" );
	set( "object", ([
		"amount3"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mogi/dragon/obj/scale",
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
	set( "build", 11094 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room563.c",
		"west"      : "/open/clan/13_luck/room/room561",
	]) );
	set( "long", @LONG
走來這裡，立刻感覺到一股魄力直逼四周，靜謐的氣氛散發全
場。此處只有屈指可數的弟子在此練武比試，以增加實戰經驗。雖
然他們的衣著十分不顯眼，但全身上下卻散發一股源源不絕的熱力
，由此看來，絕非等閒之輩。
LONG);
	setup();
	replace_program(ROOM);
}
