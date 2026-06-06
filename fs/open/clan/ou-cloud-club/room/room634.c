inherit ROOM;
void create() {
	set( "short", "小叡寶貝" );
	set( "object", ([
		"amount2"  : 9,
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
		"amount4"  : 1,
		"file6"    : "/obj/stone/powder",
		"amount3"  : 1,
		"file5"    : "/open/magic-manor/obj/master_snake_head",
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"amount9"  : 1,
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"file2"    : "/obj/stone/suipian",
		"file1"    : "/obj/stone/jiao",
		"amount8"  : 1,
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"amount10" : 1,
		"amount1"  : 7,
		"amount5"  : 1,
		"amount6"  : 10,
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
	]) );
	set( "build", 10103 );
	set( "owner", "dklove" );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room173.c",
		"north"     : "/open/clan/ou-cloud-club/room/room632",
		"east"      : "/open/clan/ou-cloud-club/room/room633.c",
	]) );
	set( "long", @LONG
我愛小叡 小叡愛我 我愛小叡 小叡愛我
我愛小叡 小叡愛我 我愛小叡 小叡愛我
我愛小叡 小叡愛我 我愛小叡 小叡愛我
我愛小叡 小叡愛我 我愛小叡 小叡愛我
我愛小叡 小叡愛我 我愛小叡 小叡愛我
我愛小叡 小叡愛我 我愛小叡 小叡愛我
我愛小叡 小叡愛我 我愛小叡 小叡愛我
LONG);
	setup();
	replace_program(ROOM);
}
