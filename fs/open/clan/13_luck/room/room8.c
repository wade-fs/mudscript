inherit ROOM;
void create() {
	set( "short", "皇城大道" );
	set( "object", ([
		"amount4"  : 1,
		"file6"    : "/open/center/obj/mechoufen-head",
		"file3"    : "/open/center/obj/mechoufen-head",
		"amount3"  : 1,
		"file10"   : "/open/center/obj/mechoufen-head",
		"file7"    : "/open/center/obj/mechoufen-head",
		"amount7"  : 1,
		"amount8"  : 1,
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount9"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/ghost-hole/obj/light-spirit",
		"amount1"  : 1,
		"file8"    : "/open/center/obj/mechoufen-head",
		"amount10" : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/center/obj/mechoufen-head",
		"file1"    : "/open/ghost-hole/obj/light-spirit",
		"file4"    : "/open/center/obj/mechoufen-head",
	]) );
	set( "build", 10231 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room6.c",
		"north"     : "/open/clan/13_luck/room/room11",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    出了柳月泉，一條筆直的大道呈現在你眼前，乃通往十三吉祥禁地
--- 皇城之唯一通道，傳說中凡進入皇城者, 從無完體而出之人，只因
皇城內滿佈十三吉祥之高手，各個都是滿手鮮血的無情殺手，一但身入
皇城, 只有無盡的殺戮等著你...

LONG);
	setup();
	replace_program(ROOM);
}
