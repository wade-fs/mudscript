inherit ROOM;
void create() {
	set( "short", "驚雲閣" );
	set( "owner", "soul" );
	set( "object", ([
		"amount7"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"amount9"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount10" : 1,
		"amount1"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount8"  : 1,
		"amount6"  : 1,
		"file9"    : "/open/magic-manor/obj/sun-heart",
		"amount3"  : 1,
		"file7"    : "/open/magic-manor/obj/lunar-heart",
		"file10"   : "/obj/gift/xisuidan",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file8"    : "/open/magic-manor/obj/sun-heart",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount5"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-ring",
	]) );
	set( "build", 10181 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room638",
		"west"      : "/open/clan/13_luck/room/room639.c",
		"south"     : "/open/clan/13_luck/room/room641",
	]) );
	set( "long", @LONG

    經過天地五行陣的試煉，終於來到赫赫有名的雅居─
『驚雲閣』。巨大的扁額高掛，名貴的擺設，處處都顯示
出主人的不凡。若是有幸的話，或許可以見上一面。
    經過天地五行陣的試煉，終於來到赫赫有名的雅居─
『驚雲閣』。巨大的扁額高掛，名貴的擺設，處處都顯示
出主人的不凡。若是有幸的話，或許可以見上一面。

LONG);
	setup();
	replace_program(ROOM);
}
