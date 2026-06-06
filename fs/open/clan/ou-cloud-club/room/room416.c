inherit ROOM;
void create() {
	set( "short", "$HIR$火焰之舞$NOR$" );
	set( "object", ([
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount10" : 1,
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"amount6"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"amount7"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount3"  : 1,
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount2"  : 1,
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount9"  : 1,
		"amount8"  : 1,
	]) );
	set( "build", 10555 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room417.c",
		"south"     : "/open/clan/ou-cloud-club/room/room516",
		"west"      : "/open/clan/ou-cloud-club/room/room415.c",
		"north"     : "/open/clan/ou-cloud-club/room/room165.c",
	]) );
	set( "long", @LONG
這一道迴廊是用硬度極高的『焱石』所建造的，據說是掌管
火焰的上古炎獸『伊弗利特』所製造的，除了水火不侵之外還兼
具了冬暖夏涼的特點，而兩旁的牆壁上有不少的小孔，聽說裡頭
暗藏機關，但詳細情形只有幫主以及長老知道而已。

北邊現在是Ads的家。

LONG);
	setup();
	replace_program(ROOM);
}
