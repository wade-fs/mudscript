inherit ROOM;
void create() {
	set( "short", "幽暗小徑" );
	set( "object", ([
		"amount6"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount5"  : 1,
		"amount1"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount3"  : 1,
		"amount9"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount4"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount7"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-pants",
	]) );
	set( "build", 10256 );
	set( "exits", ([
		"southeast" : "/open/clan/dark-forest/room/room10",
		"north"     : "/open/clan/dark-forest/room/room3.c",
	]) );
	set( "long", @LONG
越往前進，身旁的樹叢也越來越茂密，哨兵樹、城心樹、
橡樹以及魚梁木等等彼此交錯盤旋，就像是一座深綠色的壁壘
為幽暗密林抵抗入侵者，偶而放慢腳步用心傾聽，似乎還能聽
見樹木的耳語呢喃，讓你的心靈舒緩沉澱。

LONG);
	setup();
	replace_program(ROOM);
}
