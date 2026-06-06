inherit ROOM;
void create() {
	set( "short", "$HIR$火焰之舞$NOR$" );
	set( "object", ([
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount8"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount4"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
	]) );
	set( "build", 10269 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room419.c",
		"south"     : "/open/clan/ou-cloud-club/room/room84",
		"west"      : "/open/clan/ou-cloud-club/room/room417.c",
		"north"     : "/open/clan/ou-cloud-club/room/room85.c",
	]) );
	set( "long", @LONG
這一道迴廊是用硬度極高的『焱石』所建造的，據說是掌管
火焰的上古炎獸『伊弗利特』所製造的，除了水火不侵之外還兼
具了冬暖夏涼的特點，而兩旁的牆壁上有不少的小孔，聽說裡頭
暗藏機關，但詳細情形只有幫主以及長老知道而已。突然你的身
旁閃過一道黑影，定神一看，原來是可愛的冰燄獸(s_dracula)

北邊現在是小悟刀(Hgf)的家。 南邊是悟刀生(Pobpob)的窩。

LONG);
	setup();
	replace_program(ROOM);
}
