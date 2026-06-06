inherit ROOM;
void create() {
	set( "short", "風雲閣入口" );
	set( "owner", "smalloo" );
	set( "object", ([
		"file10"   : "/obj/gift/xisuidan",
		"file5"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount1"  : 1,
		"amount4"  : 1,
		"file9"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount9"  : 1,
		"file1"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount5"  : 1,
		"file3"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount2"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount10" : 1,
		"file4"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount7"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file6"    : "/open/killer/obj/bellstar",
		"file2"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount6"  : 41949,
	]) );
	set( "build", 11226 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room76.c",
		"enter"     : "/open/clan/13_luck/room/room339",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    映入你眼簾的是一幢巍峨的建築，雖然沒有雕龍飛柱，但是，門
卻是用風跟雲兩個字所做的入口而在風跟雲兩個字上面寫這一句話，
       成   也   風   雲
       敗   也   風   雲
 
屹立於一大片曠野上，顯得格外氣派威武，此時微風徐徐吹來，
天上的雲層也有點兒飄忽不定，令你覺的毛骨聳然。


LONG);
	setup();
	replace_program(ROOM);
}
