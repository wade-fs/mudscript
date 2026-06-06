inherit ROOM;
void create() {
	set( "short", "湖心小築" );
	set( "owner", "zeros" );
	set( "object", ([
		"amount9"  : 1,
		"file6"    : "/obj/gift/xisuidan",
		"file8"    : "/obj/gift/shenliwan",
		"file9"    : "/obj/gift/shenliwan",
		"file7"    : "/obj/gift/shenliwan",
		"file1"    : "/open/killer/obj/atman_pill",
		"amount7"  : 1,
		"amount8"  : 1,
		"amount3"  : 502,
		"amount4"  : 1,
		"amount1"  : 449,
		"file5"    : "/obj/gift/xiandan",
		"amount5"  : 1,
		"amount2"  : 100,
		"amount6"  : 1,
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"file2"    : "/open/mogi/castle/obj/sspill",
		"file4"    : "/obj/gift/xisuidan",
	]) );
	set( "light_up", 1 );
	set( "build", 10020 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room195.c",
		"up"        : "/open/clan/13_luck/room/room238.c",
		"east"      : "/open/clan/13_luck/room/room423",
		"south"     : "/open/clan/13_luck/room/room194.c",
		"west"      : "/open/clan/13_luck/room/room367",
		"out"       : "/open/clan/13_luck/room/room118.c",
	]) );
	set( "long", @LONG
這是一個與世隔絕的地方,四周的空氣瀰漫著花香,樹林傳來陣陣的鳥語,
這裡遠離了世俗的塵埃,是一個稀少人會知道的世外仙境,沒有戰爭只有
和平,也因為這裡的寧靜正好是一個讓人能夠快速修養身心的好地方,
如果你有足夠的緣分到達此世外仙境,希望你自己可以保持此仙境的寧靜和平.
LONG);
	setup();
	replace_program(ROOM);
}
