inherit ROOM;
void create() {
	set( "short", "二樓的走廊" );
	set( "owner", "panhermes" );
	set( "object", ([
		"file3"    : "/open/fire-hole/obj/w-pill",
		"file4"    : "/open/fire-hole/obj/r-pill",
		"amount4"  : 2,
		"amount2"  : 1,
		"file7"    : "/obj/gift/xiandan",
		"amount3"  : 2,
		"file1"    : "/open/mogi/castle/obj/black-ghost-head",
		"file5"    : "/open/mogi/castle/obj/sspill",
		"amount5"  : 49,
		"amount1"  : 1,
		"file2"    : "/open/mogi/castle/obj/seven7-dark-head",
		"amount7"  : 1,
	]) );
	set( "build", 10066 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room387",
		"south"     : "/open/clan/sky-wu-chi/room/room313",
		"west"      : "/open/clan/sky-wu-chi/room/room384.c",
	]) );
	set( "long", @LONG
一陣耀眼的光芒刺得讓你幾乎睜不開眼，你瞇著眼睛一看，原來走廊的兩側掛滿
了大小不一的鏡子，有的小如方糖，有的大如一扇門；像拼圖般地把兩側的牆填
的滿滿，令你覺的好像有人在窺視你，卻又看不到其他人影。往南走可以到達國
王的寢宮，往西走則是白雪公主的臥室，往下走你可以回到原來的地方。
LONG);
	setup();
	replace_program(ROOM);
}
