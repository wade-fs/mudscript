inherit ROOM;
void create() {
	set( "short", "$HIC$【醫藥寶物專櫃】$NOR$" );
	set( "owner", "peiyi" );
	set( "light_up", 1 );
	set( "object", ([
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount8"  : 15,
		"amount2"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mon/obj/ghost-helmet",
		"file8"    : "/open/mogi/castle/obj/sspill",
		"amount4"  : 1,
		"amount5"  : 1,
		"file2"    : "/open/magic-manor/obj/fire-ball",
		"amount10" : 1,
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/obj/wood-ball",
		"file7"    : "/open/doctor/pill/ice_pill",
		"file9"    : "/open/doctor/pill/ff_pill",
		"file10"   : "/open/capital/guard/gring",
		"file5"    : "/open/mon/obj/ghost-cloak",
		"amount3"  : 1,
		"amount7"  : 198,
		"amount9"  : 123,
		"amount6"  : 1,
	]) );
	set( "build", 10231 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room226",
	]) );
	set( "long", @LONG
    你打開北邊的小櫃子，迎面撲鼻而來的是一陣陣淡淡清香的丹藥味
道，很明顯這裡放著小佩佩個人收藏的奇珍妙藥，不過你仔細的觀察，
可以發現其實裡面還是有一些很「家常」的藥，像是恢復體力，恢復狀
態等等平常可見的藥。在藥品的旁邊，也放了一些有趣的寶物，特別的
寶物，或者是神奇妙用的寶物，這一些寶物是小佩佩周遊各地，與各地
方的先進耆老們請教交換或者討來的，有一些是你看也沒看過的東西，
真是讓人好奇這些是從哪裡來的。
LONG);
	setup();
	replace_program(ROOM);
}
