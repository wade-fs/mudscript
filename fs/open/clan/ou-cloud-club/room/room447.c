inherit ROOM;
void create() {
	set( "short", "$HIR$鳳凰路$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"amount1"  : 1,
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"amount6"  : 1,
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount5"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount4"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount10" : 1,
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "build", 11442 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room246.c",
		"north"     : "/open/clan/ou-cloud-club/room/room172.c",
		"south"     : "/open/clan/ou-cloud-club/room/room253",
		"east"      : "/open/clan/ou-cloud-club/room/room446.c",
	]) );
	set( "long", @LONG
光芒四射的空間讓你全身上下的充滿了活力，偶然間飄落的
火紅色羽毛緩緩的落在你的手間，不死火鳥『菲尼克斯』的身影
緩緩的在遠端出現‧突然間手上的火羽慢慢燃燒，伴隨淡藍色的
火焰慢慢消失，火鳥也振翅高飛消失在你的眼前‧

北邊是含笑半步癲(llaa)的房間，南邊是剛強(roboii)的房間。

LONG);
	setup();
	replace_program(ROOM);
}
