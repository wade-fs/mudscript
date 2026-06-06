inherit ROOM;
void create() {
	set( "short", "魔刀傑庫" );
	set( "owner", "dragon" );
	set( "object", ([
		"file2"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file5"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"file1"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount9"  : 1,
		"file6"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"file7"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file3"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount1"  : 1,
		"amount5"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
	]) );
	set( "build", 10073 );
	set( "exits", ([
		"east"      : "/open/clan/free-zone/room/room33",
	]) );
	set( "long", @LONG

 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★
★~╭┬┐☆☆╭┬┐☆☆╭┬┐☆☆╭┬┐~★
☆~├魔┤☆☆├刀┤☆☆├傑┤☆☆├庫┤~☆
★~└┴┘☆☆└┴┘☆☆└┴┘☆☆└┴┘~★
 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★


LONG);
	setup();
	replace_program(ROOM);
}
