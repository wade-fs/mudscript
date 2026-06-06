inherit ROOM;
void create() {
	set( "short", "十三劍堂正殿" );
	set( "object", ([
		"amount4"  : 1,
		"file3"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount1"  : 1,
		"file4"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount8"  : 1,
		"file6"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount7"  : 1,
		"file5"    : "/open/magic-manor/obj/evil-kill-claw",
		"file8"    : "/obj/gift/xisuidan",
		"amount2"  : 1,
		"amount10" : 1,
		"amount3"  : 1,
		"file7"    : "/obj/gift/xisuidan",
		"file10"   : "/obj/gift/xiandan",
		"amount9"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/magic-manor/obj/evil-kill-claw",
		"file9"    : "/obj/gift/xiandan",
	]) );
	set( "owner", "roar" );
	set( "build", 10026 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room376.c",
		"west"      : "/open/clan/13_luck/room/room378.c",
		"east"      : "/open/clan/13_luck/room/room374",
		"north"     : "/open/clan/13_luck/room/room375.c",
	]) );
	set( "long", @LONG

    走入十三劍堂的正殿，你不禁嚇了一跳，四周圍的劍多的讓你無法想
像。在這些劍裡頭不乏有些當世名劍，而大殿的後方所掛的大圖正是劍堂
第一代堂主天道劍邪的肖像。正殿之中所站的那個人正是現在的劍堂堂主
『劍十三』。他看起來雖然年輕但其所學已得劍邪所真傳，向他打聽劍邪
的下落是在恰當不過的。

LONG);
	setup();
	replace_program(ROOM);
}
