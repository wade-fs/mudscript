inherit ROOM;
void create() {
	set( "short", "$HIG$殺意魔錐$NOR$" );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room447",
	]) );
	set( "object", ([
		"file8"    : "/open/snow/obj/stone",
		"amount1"  : 99999,
		"amount5"  : 1,
		"file2"    : "/open/killer/obj/bellstar",
		"file5"    : "/open/snow/obj/snow_token",
		"amount8"  : 1,
		"file9"    : "/open/killer/obj/bellstar",
		"file7"    : "/open/killer/obj/bellstar",
		"amount4"  : 99999,
		"file1"    : "/open/killer/obj/bellstar",
		"amount10" : 99999,
		"amount7"  : 99999,
		"file6"    : "/open/killer/obj/bellstar",
		"amount2"  : 99999,
		"amount6"  : 99999,
		"amount3"  : 99999,
		"file4"    : "/open/killer/obj/bellstar",
		"file3"    : "/open/killer/obj/bellstar",
		"amount9"  : 99999,
		"file10"   : "/open/killer/obj/bellstar",
	]) );
	set( "build", 17889 );
	set( "light_up", 1 );
	set( "long", @LONG
光芒四射的空間讓你全身上下的充滿了活力，偶然間飄落的
火紅色羽毛緩緩的落在你的手間，不死火鳥『菲尼克斯』的身影
緩緩的在遠端出現‧突然間手上的火羽慢慢燃燒，伴隨淡藍色的
火焰慢慢消失，火鳥也振翅高飛消失在你的眼前‧


LONG);
	setup();
	replace_program(ROOM);
}
