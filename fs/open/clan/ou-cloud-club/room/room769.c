inherit ROOM;
void create() {
	set( "short", "巨木林" );
	set( "owner", "turtle" );
	set( "object", ([
		"amount10" : 1,
		"file7"    : "/open/snow/obj/snow_token",
		"file8"    : "/open/killer/obj/soul-hands",
		"amount1"  : 1,
		"amount8"  : 1,
		"file3"    : "/open/main/room/sp/stone",
		"file1"    : "/open/killer/obj/soul-hands",
		"file5"    : "/obj/gift/shenliwan",
		"file6"    : "/obj/gift/shenliwan",
		"amount6"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/start/obj/green_hat",
		"file10"   : "/open/killer/obj/soul-hands",
		"amount2"  : 1,
		"amount5"  : 1,
		"file4"    : "/obj/gift/unknowdan",
		"amount3"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10556 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room770.c",
		"down"      : "/open/clan/ou-cloud-club/room/room752",
		"west"      : "/open/clan/ou-cloud-club/room/room771.c",
		"out"       : "/open/clan/ou-cloud-club/room/room744.c",
	]) );
	set( "long", @LONG
不按前人走過的道路，穿過巨木間的小縫隙，一步步的往森林深處走去
，看到樹幹上長滿了青苔，難以攀爬，好在要來之前，早已準備了一些裝備
，只要找到適當的地方，就可以攀爬而上了，而在地上的爛泥巴讓你行走困
難，周圍的小草上有幾隻瓢蟲與甲蟲在那兒休憩，每一處每一處都可說不失
原始森林的味道。
LONG);
	setup();
	replace_program(ROOM);
}
