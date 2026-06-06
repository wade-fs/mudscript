inherit ROOM;
void create() {
	set( "short", "南側走道" );
	set( "object", ([
		"amount7"  : 1,
		"file5"    : "/obj/gift/xiandan",
		"amount9"  : 1,
		"amount10" : 1,
		"file3"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount2"  : 1,
		"amount3"  : 1,
		"file2"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount1"  : 1,
		"file7"    : "/obj/gift/xisuidan",
		"file1"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount4"  : 1,
		"file9"    : "/obj/gift/xisuidan",
		"amount5"  : 1,
		"amount8"  : 1,
		"file8"    : "/obj/gift/shenliwan",
		"amount6"  : 1,
		"file6"    : "/obj/gift/unknowdan",
		"file10"   : "/obj/gift/unknowdan",
		"file4"    : "/open/magic-manor/obj/lin-cloud-fan",
	]) );
	set( "owner", "roar" );
	set( "build", 11772 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room384.c",
		"north"     : "/open/clan/13_luck/room/room379",
	]) );
	set( "long", @LONG

    這條道路是通往十三吉祥四大分堂中『十三戰堂』的道路，兩旁豎立
著代表十三戰堂的軍旗，戰堂弟子亦在此四處巡邏，以防不速之客闖入十
三戰堂。往南看去十三戰堂的大門已浮現在你的眼前，想一窺戰堂是個什
麼樣的地方的你，不由自主的往南走去。

LONG);
	setup();
	replace_program(ROOM);
}
