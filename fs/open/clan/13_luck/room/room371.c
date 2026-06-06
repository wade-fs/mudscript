inherit ROOM;
void create() {
	set( "short", "南側走道" );
	set( "object", ([
		"amount8"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount6"  : 1,
		"amount5"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount4"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount9"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-helmet",
	]) );
	set( "owner", "roar" );
	set( "build", 10035 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room398",
		"north"     : "/open/clan/13_luck/room/room372.c",
	]) );
	set( "long", @LONG

    這裡是通往十三吉祥四大分堂中『十三拳堂』的唯一道路，道路兩旁
跟其他三大分堂的裝飾完全不同。兩旁牆上所雕塑的都是有關現今武林各
大門派著名的拳法招式，讓經過這兒的你不禁嚇了一大跳，心中盤算到十
三拳堂的堂主到底是何許人物，盡可以網羅天下各門的獨門武學。再往南
走下去就到十三拳堂的大門了。

LONG);
	setup();
	replace_program(ROOM);
}
