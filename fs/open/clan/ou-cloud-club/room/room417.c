inherit ROOM;
void create() {
	set( "short", "$HIR$火焰之舞$NOR$" );
	set( "object", ([
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount10" : 1,
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"amount6"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount7"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount3"  : 1,
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount2"  : 1,
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount9"  : 1,
		"amount8"  : 1,
	]) );
	set( "item_desc", ([
		"s_dracula" : @ITEM

在你眼前的是一隻全身被火焰包覆的冰燄獸，正當你想要走
近看個仔細的時候，冰燄獸突然張開大口醺得你暈頭轉向，
然後從口中噴出一堆冰塊砸得你滿頭包，在你還沒回過神的
時候又一溜煙的跑掉了‧

ITEM,
	]) );
	set( "build", 10493 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room418.c",
		"south"     : "/open/clan/ou-cloud-club/room/room83",
		"west"      : "/open/clan/ou-cloud-club/room/room416.c",
		"north"     : "/open/clan/ou-cloud-club/room/room411.c",
	]) );
	set( "long", @LONG
這一道迴廊是用硬度極高的『焱石』所建造的，據說是掌管
火焰的上古炎獸『伊弗利特』所製造的，除了水火不侵之外還兼
具了冬暖夏涼的特點，而兩旁的牆壁上有不少的小孔，聽說裡頭
暗藏機關，但詳細情形只有幫主以及長老知道而已。突然你的身
旁閃過一道黑影，定神一看，原來是可愛的冰燄獸(s_dracula)

北邊現在是維克(Vicker)的家。 南邊是劍流星(Aspire)的窩。

LONG);
	setup();
	replace_program(ROOM);
}
