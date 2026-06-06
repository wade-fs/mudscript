inherit ROOM;
void create() {
	set( "short", "驚雁宮" );
	set( "owner", "icute" );
	set( "object", ([
		"amount5"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 625,
		"file9"    : "/open/killer/obj/atman_pill",
		"file1"    : "/open/capital/obj/gold_pill",
		"amount8"  : 1,
		"file6"    : "/open/fire-hole/obj/p-pill",
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"amount9"  : 312,
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"amount3"  : 1,
		"amount7"  : 1,
		"amount4"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10015 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room97",
	]) );
	set( "long", @LONG
驚雁宮佔地極廣，殿閣亭台，氣象肅森，依山勢而建，背靠千里崗
主峰驚雁峰，亦呈行宮得名之來由。驚雁峰高插入雲，秀出群山之上，
使驚雁宮雄視整個留馬平原，留馬驛在左上方的七里遠處。全宮除主殿
偏殿以一種近乎大理石的質料所建外，其他都是木構建築。
LONG);
	setup();
	replace_program(ROOM);
}
