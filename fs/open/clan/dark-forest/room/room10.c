inherit ROOM;
void create() {
	set( "short", "幽暗小徑" );
	set( "object", ([
		"amount9"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount7"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount5"  : 1,
		"amount3"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount1"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-armband",
	]) );
	set( "build", 12321 );
	set( "exits", ([
		"south"     : "/open/clan/dark-forest/room/room11",
		"northwest" : "/open/clan/dark-forest/room/room9.c",
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
