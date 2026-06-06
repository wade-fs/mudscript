inherit ROOM;
void create() {
	set( "short", "我愛小叡" );
	set( "object", ([
		"file1"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount1"  : 10,
		"amount5"  : 1,
		"amount10" : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount6"  : 1,
		"amount9"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount4"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-ring",
	]) );
	set( "build", 10091 );
	set( "owner", "dklove" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room634",
	]) );
	set( "long", @LONG
我愛小叡 我愛小叡 我愛小叡 我愛小叡 我愛小叡

我愛小叡 我愛小叡 我愛小叡 我愛小叡 我愛小叡

我愛小叡 我愛小叡 我愛小叡 我愛小叡 我愛小叡

我愛小叡 我愛小叡 我愛小叡 我愛小叡 我愛小叡

我愛小叡 我愛小叡 我愛小叡 我愛小叡 我愛小叡
LONG);
	setup();
	replace_program(ROOM);
}
