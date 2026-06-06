inherit ROOM;
void create() {
	set( "short", "$HBCYN$天晶結界$NOR$" );
	set( "owner", "neun" );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room29",
	]) );
	set( "object", ([
		"file5"    : "/open/ping/questsfan/obj/diamond_armor",
		"amount9"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/ping/questsfan/obj/diamond_hairpin",
		"amount6"  : 1,
		"file1"    : "/open/ping/questsfan/obj/diamond_cloak",
		"amount3"  : 1,
		"amount4"  : 1,
		"amount10" : 1,
		"file3"    : "/open/ping/questsfan/obj/diamond_belt",
		"file4"    : "/open/ping/questsfan/obj/diamond_hands",
		"file6"    : "/open/ping/questsfan/obj/diamond_boots",
		"file2"    : "/open/ping/questsfan/obj/diamond_armor",
		"file10"   : "/open/ping/questsfan/obj/diamond_boots",
		"amount1"  : 1,
		"amount5"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10347 );
	set( "long", @LONG
傳說中書生最好的裝備,虹晶裝備全套,雖然是針對書生設計的,但其實對於其他
門派來說,其實也是不錯的防身裝備.所以幫主平時特別準備三套此種裝備,置於此結
界中,讓幫眾在偷懶或是緊急的時候可以來此拿取,結界的頂端刻著幫主的叮嚀,希望
幫眾使用完後都能自動歸還

LONG);
	setup();
	replace_program(ROOM);
}
