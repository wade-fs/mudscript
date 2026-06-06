inherit ROOM;
void create() {
	set( "short", "幽暗小徑" );
	set( "object", ([
		"amount7"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount8"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount4"  : 1,
		"amount6"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount1"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount9"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount10" : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gem",
	]) );
	set( "build", 11907 );
	set( "exits", ([
		"north"     : "/open/clan/dark-forest/room/room10",
	]) );
	set( "long", @LONG
一踏進這裡，天空就彷彿蓋上了一層墨綠色的簾幕，黑暗
的冰冷手指輕拂你孤單的身影，矗立在你身旁的是有著瘦長身
材的哨兵樹，不經意地抬頭仰望，你好像看到模糊的身影搖曳
；小徑深處有股神奇的魔力催促你繼續往前。

LONG);
	setup();
	replace_program(ROOM);
}
