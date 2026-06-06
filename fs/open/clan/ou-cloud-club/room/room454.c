inherit ROOM;
void create() {
	set( "short", "魔劍丹藥室5" );
	set( "owner", "mekyn" );
	set( "object", ([
		"amount1"  : 2,
		"file1"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file2"    : "/open/fire-hole/obj/b-pill",
		"amount3"  : 3,
		"amount2"  : 3,
		"amount7"  : 7,
		"file7"    : "/open/ping/obj/poison_pill",
		"file3"    : "/open/fire-hole/obj/g-pill",
	]) );
	set( "build", 10826 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room455",
	]) );
	set( "long", @LONG

                              ║
                        ╭╮  ║  ╭╮
                      ╭═║╮║╭║═╮
                    ╭═║═║═║═║═╮
                    ╰║═║╯╰╯║═║╯
                      ╰║╯◤█◥╰║╯
                        ║  ███  ║
                      ╭║╮◥▓◤╭║╮
                    ╭║═║╮║╭║═║╮
                    ╰═║═║═║═║═╯
                      ╰═║╯║╰║═╯
                        ╰╯  ◎  ╰╯


LONG);
	setup();
	replace_program(ROOM);
}
