inherit ROOM;
void create() {
	set( "short", "光碟片 防具室" );
	set( "object", ([
		"amount8"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"file6"    : "/open/mogi/dragon/obj/power",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 12657 );
	set( "owner", "cdrom" );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room297",
	]) );
	set( "long", @LONG
光碟片在歷盡了千辛萬苦、拔山涉水、千里迢迢的從各地收集來的
各式各樣寶貴武器，皆被嚴密的收藏在此處保管。你看到兩側一排的守
衛士兵冷眼瞪著你，讓你打從心底不敢在這邊亂來。想想還是早點來離
開此處才是上策。
LONG);
	setup();
	replace_program(ROOM);
}
