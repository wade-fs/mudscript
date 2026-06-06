inherit ROOM;
void create() {
	set( "short", "刀塚" );
	set( "owner", "kaien" );
	set( "object", ([
		"file3"    : "/open/fire-hole/obj/g-pill",
		"amount1"  : 8,
		"amount6"  : 1,
		"file4"    : "/open/mogi/castle/obj/sspill",
		"file8"    : "/open/ghost-hole/obj/fire-spirit",
		"amount10" : 1,
		"file2"    : "/open/ghost-hole/obj/light-spirit",
		"file10"   : "/open/ghost-hole/obj/light-spirit",
		"amount3"  : 158,
		"amount2"  : 1,
		"file7"    : "/open/mogi/castle/obj/sspill",
		"file1"    : "/open/mon/obj/thousand-nectar",
		"amount8"  : 1,
		"amount4"  : 5,
		"file5"    : "/open/mogi/castle/obj/leave",
		"amount7"  : 6,
		"file6"    : "/open/gsword/obj1/bpball",
		"amount5"  : 1,
		"amount9"  : 1,
		"file9"    : "/open/killer/obj/k_ring",
	]) );
	set( "build", 11826 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room352",
		"north"     : "/open/clan/13_luck/room/room342.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    經過狹小通道後，你來到一個巨大的洞穴之中，只見四周的土地
上有六座大小不一的墳墓，其中一座最大的墳墓上插者一把陰靈邪氣
的刀中方的墓碑上(stone)似乎有東西，你心情興奮的想調查(check)
                                 
                            (金)
                             ＊
                   (火)＊    ＊    ＊(木)
                            (心)
                          ＊　　＊
                         (水)  (土)

LONG);
	setup();
	replace_program(ROOM);
}
