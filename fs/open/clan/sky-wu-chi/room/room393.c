inherit ROOM;
void create() {
	set( "short", "葛朗皮的葡萄園" );
	set( "owner", "panhermes" );
	set( "object", ([
		"amount10" : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file9"    : "/obj/gift/xiandan",
		"amount8"  : 1,
		"file5"    : "/obj/gift/hobowdan",
		"amount1"  : 164,
		"file1"    : "/open/mon/obj/mon-pill",
		"file4"    : "/obj/gift/xiandan",
		"file3"    : "/obj/gift/xiandan",
		"file8"    : "/obj/gift/unknowdan",
		"file10"   : "/obj/gift/xiandan",
		"file6"    : "/obj/gift/unknowdan",
		"amount3"  : 1,
		"amount9"  : 1,
	]) );
	set( "build", 10150 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room391",
		"west"      : "/open/clan/sky-wu-chi/room/room394.c",
	]) );
	set( "long", @LONG
這裡是七個小矮人所種植的葡萄園，你發覺每粒葡萄都令人垂涎欲滴，每串葡萄
只有七粒，每棵葡萄樹只結七串，而這個葡萄園只有七株葡萄樹，而葡萄園的入
口立著一個牌子(sign)。往東走是史利平的葡萄園。.....................
LONG);
	setup();
	replace_program(ROOM);
}
