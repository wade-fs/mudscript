inherit ROOM;
void create() {
	set( "short", "$HIR$鳳凰路$NOR$" );
	set( "object", ([
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount7"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount5"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"amount9"  : 1,
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount8"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"amount1"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount4"  : 1,
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
	]) );
	set( "build", 10246 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room446.c",
		"east"      : "/open/clan/ou-cloud-club/room/room442.c",
		"north"     : "/open/clan/ou-cloud-club/room/room218.c",
		"south"     : "/open/clan/ou-cloud-club/room/room302",
	]) );
	set( "long", @LONG
光芒四射的空間讓你全身上下的充滿了活力，偶然間飄落的
火紅色羽毛緩緩的落在你的手間，不死火鳥『菲尼克斯』的身影
緩緩的在遠端出現‧突然間手上的火羽慢慢燃燒，伴隨淡藍色的
火焰慢慢消失，火鳥也振翅高飛消失在你的眼前‧

北邊是輕舞飛揚(Flyindance)的家，南邊是炎之龍(bleak)的房子。

LONG);
	setup();
	replace_program(ROOM);
}
