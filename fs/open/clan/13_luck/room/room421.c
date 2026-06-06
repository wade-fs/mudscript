inherit ROOM;
void create() {
	set( "short", "吉祥廣場二" );
	set( "object", ([
		"amount9"  : 1,
		"file5"    : "/open/magic-manor/obj/master_snake_head",
		"file3"    : "/open/magic-manor/obj/master_snake_head",
		"amount7"  : 1,
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file1"    : "/open/magic-manor/obj/master_snake_head",
		"amount10" : 1,
		"file2"    : "/open/magic-manor/obj/master_snake_head",
		"amount1"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/magic-manor/obj/master_snake_head",
		"file4"    : "/open/magic-manor/obj/master_snake_head",
		"file10"   : "/obj/gift/xiandan",
		"amount5"  : 1,
		"amount8"  : 1,
		"file6"    : "/open/magic-manor/obj/master_snake_head",
		"amount6"  : 1,
		"amount4"  : 1,
	]) );
	set( "owner", "mwf" );
	set( "build", 10011 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room420",
		"south"     : "/open/clan/13_luck/room/room422.c",
	]) );
	set( "long", @LONG

    廣場並不很大，但也足可站上個百來人左右，這裡是整個廣場的左側
你可以望見右前方有個高臺，現在因為沒有人使用，廣場上有些行人在這
裡來來去去的，你看到路旁有個乞丐，模樣蠻可憐的，果然再繁榮的城市
也一樣會有乞丐的存在。

LONG);
	setup();
	replace_program(ROOM);
}
