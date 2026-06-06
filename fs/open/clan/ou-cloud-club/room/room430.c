inherit ROOM;
void create() {
	set( "short", "$HIY$Ｒａｙｋ$HIW$的$HIC$家$NOR$" );
	set( "owner", "rayk" );
	set( "object", ([
		"amount1"  : 9517,
		"amount7"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/ping/obj/poison_pill",
		"file2"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount2"  : 155,
		"amount4"  : 698,
		"amount8"  : 1371,
		"amount9"  : 1,
		"file3"    : "/open/mogi/castle/obj/sspill",
		"file1"    : "/open/killer/obj/atman_pill",
		"amount5"  : 285,
		"amount10" : 1,
		"file8"    : "/open/mon/obj/mon-pill",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 849,
		"amount6"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10240 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room581.c",
		"down"      : "/open/clan/ou-cloud-club/room/room724",
		"north"     : "/open/clan/ou-cloud-club/room/room439.c",
		"south"     : "/open/clan/ou-cloud-club/room/room562.c",
		"east"      : "/open/clan/ou-cloud-club/room/room580.c",
		"up"        : "/open/clan/ou-cloud-club/room/room627",
	]) );
	set( "long", @LONG

    牆上一個個的拳印，磨損不堪的地板，這裡就是Ｒａｙｋ的家。
Ｒａｙｋ常常在這裡習武練氣，所以房子裡面到處是打鬥的痕跡。房
間裡擺飾極少，僅一床一桌，顯示出Ｒａｙｋ一貧如洗，但他卻怡然
自得，一點都不以這種簡陋簡陋的生活為苦。

LONG);
	setup();
	replace_program(ROOM);
}
