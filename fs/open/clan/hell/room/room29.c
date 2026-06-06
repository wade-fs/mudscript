inherit ROOM;
void create() {
	set( "short", "$HBCYN$天晶結界$NOR$" );
	set( "owner", "neun" );
	set( "object", ([
		"file3"    : "/open/killer/headkill/obj/world_dag",
		"file1"    : "/open/killer/headkill/obj/i_dag",
		"amount1"  : 1,
		"file5"    : "/open/main/obj/et_sword",
		"amount3"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/fire-hole/obj/r-pill",
		"file2"    : "/open/killer/obj/s_pill",
		"file6"    : "/open/fire-hole/obj/g-pill",
		"amount2"  : 260,
		"amount6"  : 9,
		"amount7"  : 4,
		"file4"    : "/open/killer/headkill/obj/w_dag",
		"amount4"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10076 );
	set( "exits", ([
		"enter"     : "/open/clan/hell/room/room76",
		"west"      : "/open/clan/hell/room/room35.c",
		"out"       : "/open/clan/hell/room/room30.c",
		"east"      : "/open/clan/hell/room/room36.c",
	]) );
	set( "long", @LONG
傳說中書生最好的裝備,虹晶裝備全套,雖然是針對書生設計的,但其實對於其他
門派來說,其實也是不錯的防身裝備.所以幫主平時特別準備三套此種裝備,置於此結
界中,讓幫眾在偷懶或是緊急的時候可以來此拿取,結界的頂端刻著幫主的叮嚀,希望
幫眾使用完後都能自動歸還

LONG);
	setup();
	replace_program(ROOM);
}
