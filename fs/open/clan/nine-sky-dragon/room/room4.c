inherit ROOM;
void create() {
	set( "short", "湖心小築" );
	set( "owner", "haoman" );
	set( "object", ([
		"amount9"  : 1,
		"amount1"  : 27,
		"amount7"  : 1,
		"amount8"  : 1,
		"file7"    : "/obj/gift/unknowdan",
		"file9"    : "/obj/gift/unknowdan",
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"file6"    : "/obj/gift/xisuidan",
		"file8"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file5"    : "/obj/gift/xisuidan",
		"amount5"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10117 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/nine-sky-dragon/room/room5.c",
		"south"     : "/open/clan/nine-sky-dragon/room/room7.c",
		"east"      : "/open/clan/nine-sky-dragon/room/room6",
		"north"     : "/open/clan/nine-sky-dragon/room/room8.c",
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
