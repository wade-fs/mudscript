inherit ROOM;
void create() {
	set( "short", "龍滅之道" );
	set( "owner", "amdxp" );
	set( "object", ([
		"file9"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount4"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount8"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount10" : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount7"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount5"  : 1,
		"amount2"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount1"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gloves",
	]) );
	set( "build", 10023 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room230",
		"north"     : "/open/clan/13_luck/room/room227",
	]) );
	set( "long", @LONG

　　四周圍靜的讓人毛骨聳然，空氣中充斥著一股作人欲嘔的血腥味
，但是路上卻沒有看到任何屍首或者打鬥過的痕跡，你踏著腳步小心
地往前走著，腳步聲和著心跳更添幾分恐怖的氣氛，不知有多少自認
是高手的人被擊斃在此。

LONG);
	setup();
	replace_program(ROOM);
}
