inherit ROOM;
void create() {
	set( "short", "$HIR$火焰之舞$NOR$" );
	set( "object", ([
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount10" : 1,
		"amount6"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount9"  : 1,
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount5"  : 1,
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount8"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"amount4"  : 1,
	]) );
	set( "build", 10610 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room416.c",
		"south"     : "/open/clan/ou-cloud-club/room/room82",
		"north"     : "/open/clan/ou-cloud-club/room/room453.c",
	]) );
	set( "long", @LONG
這一道迴廊是用硬度極高的『焱石』所建造的，據說是掌管
火焰的上古炎獸『伊弗利特』所製造的，除了水火不侵之外還兼
具了冬暖夏涼的特點，而兩旁的牆壁上有不少的小孔，聽說裡頭
暗藏機關，但詳細情形只有幫主以及長老知道而已。

北邊現在是Killua的家。

LONG);
	setup();
	replace_program(ROOM);
}
