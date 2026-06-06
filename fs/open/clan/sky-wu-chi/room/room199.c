inherit ROOM;
void create() {
	set( "short", "$HIY$【平南書院】 $HIM$天籟廳$NOR$" );
	set( "owner", "lonsan" );
	set( "object", ([
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"file8"    : "/open/ping/questsfan/obj/diamond_hands",
		"amount2"  : 1,
		"file3"    : "/open/ping/questsfan/obj/diamond_cloak",
		"amount5"  : 1,
		"amount4"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file10"   : "/open/ping/questsfan/obj/diamond_legging",
		"file2"    : "/open/ping/questsfan/obj/diamond_armor",
		"file6"    : "/open/ping/questsfan/obj/diamond_boots",
		"amount10" : 1,
		"amount3"  : 1,
		"amount1"  : 1,
		"file7"    : "/open/ping/questsfan/obj/diamond_belt",
		"amount9"  : 1,
		"file5"    : "/open/ping/questsfan/obj/diamond_hairpin",
		"file4"    : "/open/ping/questsfan/obj/diamond_skirt",
		"amount8"  : 1,
		"file1"    : "/open/ping/obj/cloud_fan",
	]) );
	set( "build", 10066 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room197",
	]) );
	set( "long", @LONG
天籟廳顧名思義就是能欣賞到天籟之音的地方，這裡也是平南書院教授『樂』
課程的所在。天籟廳大致上可以區分成三個部分，在南邊有十乘十個座位椅子，而
中間屬於表演檯部分，平時老師授課也是在表演檯裡教導學生們樂器的使用技巧及
樂理，較北邊的地方有一個落地式大屏風區隔開來，裡面放的是各式各樣的樂器，
學生們也常常把自己的東西放在這裡，此處亦嚴禁外人進入，而門口的左右兩側，
是屬於休息區的部分，但是右手邊的休息區比較沒有人會進去，那裡是學生們平日
練習樂器時常常待的地方。

LONG);
	setup();
	replace_program(ROOM);
}
