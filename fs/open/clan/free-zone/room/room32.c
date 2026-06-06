inherit ROOM;
void create() {
	set( "short", "金刀傑庫" );
	set( "owner", "dragon" );
	set( "object", ([
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount9"  : 1,
		"amount6"  : 1,
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount7"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 10061 );
	set( "exits", ([
		"west"      : "/open/clan/free-zone/room/room33",
	]) );
	set( "long", @LONG

 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★
★~╭┬┐☆☆╭┬┐☆☆╭┬┐☆☆╭┬┐~★
☆~├金┤☆☆├刀┤☆☆├傑┤☆☆├庫┤~☆
★~└┴┘☆☆└┴┘☆☆└┴┘☆☆└┴┘~★
 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★

LONG);
	setup();
	replace_program(ROOM);
}
