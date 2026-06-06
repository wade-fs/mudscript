inherit ROOM;
void create() {
	set( "short", "$HIM$≡冥魔帝冠Ⅱ≡$NOR$" );
	set( "light_up", 1 );
	set( "object", ([
		"amount8"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount1"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount5"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount2"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount9"  : 1,
		"amount10" : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-helmet",
	]) );
	set( "build", 10023 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room366",
	]) );
	set( "long", @LONG
    帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠
冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠
冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠
冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠
冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠
冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠
冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠冥魔帝冠

LONG);
	setup();
	replace_program(ROOM);
}
