inherit ROOM;
void create() {
	set( "short", "二樓的走廊(B)" );
	set( "object", ([
		"file7"    : "/open/mogi/castle/obj/seven4-dark-head",
		"amount5"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/mogi/castle/obj/black-ghost-head",
		"file2"    : "/open/mogi/castle/obj/seven5-dark-head",
		"amount2"  : 1,
		"file6"    : "/open/mogi/castle/obj/seven3-dark-head",
		"amount6"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/mogi/castle/obj/seven7-dark-head",
		"file3"    : "/open/mogi/castle/obj/white-ghost-head",
		"amount7"  : 1,
		"file5"    : "/open/mogi/castle/obj/seven2-dark-head",
	]) );
	set( "owner", "panhermes" );
	set( "build", 10048 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room385",
		"south"     : "/open/clan/sky-wu-chi/room/room383",
	]) );
	set( "long", @LONG
一陣耀眼的光芒刺得讓你幾乎睜不開眼，你瞇著眼睛一看，原來走廊的兩側掛滿
了大小不一的鏡子，有的小如方糖，有的大如一扇門；像拼圖般地把兩側的牆填
的滿滿，令你覺的好像有人在窺視你，卻又看不到其他人影。南邊是白雪公主的;寢室。
一個身穿雪白的僕人/servant/正在這兒整理打掃。
LONG);
	setup();
	replace_program(ROOM);
}
