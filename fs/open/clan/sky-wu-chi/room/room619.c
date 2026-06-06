inherit ROOM;
void create() {
	set( "short", "金色靈刀收藏室" );
	set( "object", ([
		"amount6"  : 1,
		"file4"    : "/obj/gift/hobowdan",
		"file5"    : "/obj/gift/hobowdan",
		"amount8"  : 1,
		"file1"    : "/obj/gift/hobowdan",
		"amount1"  : 1,
		"amount3"  : 1,
		"file8"    : "/obj/gift/hobowdan",
		"amount5"  : 1,
		"file7"    : "/obj/gift/hobowdan",
		"amount4"  : 1,
		"amount2"  : 1,
		"file2"    : "/obj/gift/hobowdan",
		"amount7"  : 1,
		"file6"    : "/obj/gift/hobowdan",
		"file3"    : "/obj/gift/hobowdan",
	]) );
	set( "light_up", 1 );
	set( "owner", "cdrom" );
	set( "build", 10078 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room297.c",
	]) );
	set( "long", @LONG
光碟片在歷盡了千辛萬苦、拔山涉水、千里迢迢的從各地收集來的
各式各樣寶貴防具，皆被嚴密的收藏在此處保管。你看到兩側一排的守
衛士兵冷眼瞪著你，讓你打從心底不敢在這邊亂來。想想還是早點來離
開此處才是上策。
LONG);
	setup();
	replace_program(ROOM);
}
