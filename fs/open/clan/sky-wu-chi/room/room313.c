inherit ROOM;
void create() {
	set( "short", "二樓的走廊(A)" );
	set( "owner", "panhermes" );
	set( "object", ([
		"file2"    : "/open/magic-manor/obj/hwa-je-icer",
		"file5"    : "/open/mogi/castle/obj/sspill",
		"file3"    : "/open/magic-manor/obj/evil-kill-claw",
		"file1"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount1"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/mogi/castle/obj/sspill",
		"amount4"  : 200,
		"file8"    : "/open/mogi/castle/obj/sspill",
		"file6"    : "/open/mogi/castle/obj/sspill",
		"amount8"  : 300,
		"amount2"  : 1,
		"file7"    : "/open/mogi/castle/obj/sspill",
		"amount7"  : 200,
		"file9"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount6"  : 200,
		"amount5"  : 200,
		"amount3"  : 1,
	]) );
	set( "build", 10131 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room385.c",
		"enter"     : "/open/clan/sky-wu-chi/room/room232",
	]) );
	set( "long", @LONG
一陣耀眼的光芒刺得讓你幾乎睜不開眼，你瞇著眼睛一看，原來走廊的兩側掛滿
了大小不一的鏡子，有的小如方糖，有的大如一扇門；像拼圖般地把兩側的牆填
的滿滿，令你覺的好像有人在窺視你，卻又看不到其他人影。
一個身穿背心裙的僕人/servant/正在小心翼翼地擦著鏡子。
LONG);
	setup();
	replace_program(ROOM);
}
