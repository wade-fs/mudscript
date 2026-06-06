inherit ROOM;
void create() {
	set( "short", "小豬頭的客房" );
	set( "object", ([
		"file3"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount5"  : 1,
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount9"  : 1,
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"amount10" : 1,
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"file1"    : "/obj/gift/shenliwan",
		"amount1"  : 1,
		"amount8"  : 1,
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount6"  : 1,
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 10,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "owner", "pighead" );
	set( "build", 10194 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room412",
	]) );
	set( "long", @LONG

    這裡是可愛小豬頭的客房，因為小豬頭身為一幫之主，當然每天
會有許多人來拜訪，所以這邊是提供客人休息的地方，這裡的設備比
外面五星級大飯店的設備高級，相信一定可以讓客人有賓至如歸的感
覺，這樣才能顯示小豬頭家的氣派。

LONG);
	setup();
	replace_program(ROOM);
}
