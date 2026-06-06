inherit ROOM;
void create() {
	set( "short", "幽香池" );
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
	set( "build", 10033 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room567",
		"north"     : "/open/clan/13_luck/room/room565",
	]) );
	set( "long", @LONG
隨著花香鳥語不知不覺的走到這兒，彩色繽紛的奇花讓你眼花
遼亂，兩邊有諾大的假山，中間有一澄清碧綠的池子。向前仔細一
看，池裡的錦魚、蓮花、荷葉、襯出了一幅美麗的圖畫。而細微的
流水聲和鳥鳴更譜出了一首樂章，讓你彷彿進入了一個仙境。

LONG);
	setup();
	replace_program(ROOM);
}
