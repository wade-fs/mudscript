inherit ROOM;
void create() {
	set( "short", "東側走道" );
	set( "object", ([
		"amount1"  : 1,
		"file3"    : "/obj/gift/xisuidan",
		"amount4"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/obj/gift/xiandan",
		"amount6"  : 1,
		"file2"    : "/obj/gift/xisuidan",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"amount2"  : 1,
		"file8"    : "/obj/gift/xisuidan",
		"amount10" : 1,
		"amount3"  : 1,
		"file7"    : "/obj/gift/xisuidan",
		"amount5"  : 1,
		"amount9"  : 1,
		"file10"   : "/obj/gift/xisuidan",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/obj/gift/xisuidan",
	]) );
	set( "owner", "roar" );
	set( "build", 10263 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room386.c",
		"south"     : "/open/clan/13_luck/room/room385.c",
		"east"      : "/open/clan/13_luck/room/room399",
	]) );
	set( "long", @LONG

    由十三吉祥校場東側連接下去為十三吉祥四大分堂的『十三劍堂』，
十三劍堂的第一代堂主據說是天山劍潭潭主天道劍邪，後因劍邪戰功彪炳
，所以得到浪子的首肯而外立門戶。現在的堂主在武學上亦有不錯的造詣
，故向其研討武學也是不錯的事。南方的道路則通往四大分堂中的『十三
戰堂』。

LONG);
	setup();
	replace_program(ROOM);
}
