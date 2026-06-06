inherit ROOM;
void create() {
	set( "short", "$HIR$鳳凰路$NOR$" );
	set( "object", ([
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"amount9"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount5"  : 1,
	]) );
	set( "build", 10327 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room118",
		"north"     : "/open/clan/ou-cloud-club/room/room171.c",
		"south"     : "/open/clan/ou-cloud-club/room/room170",
		"west"      : "/open/clan/ou-cloud-club/room/room445.c",
	]) );
	set( "long", @LONG
光芒四射的空間讓你全身上下的充滿了活力，偶然間飄落的
火紅色羽毛緩緩的落在你的手間，不死火鳥『菲尼克斯』的身影
緩緩的在遠端出現‧突然間手上的火羽慢慢燃燒，伴隨淡藍色的
火焰慢慢消失，火鳥也振翅高飛消失在你的眼前‧

北邊是輕舞飛揚(Windson)的風之故鄉，南邊是假面武藤(Mutu)的藏劍居。

LONG);
	setup();
	replace_program(ROOM);
}
