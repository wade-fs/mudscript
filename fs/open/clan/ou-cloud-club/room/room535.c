inherit ROOM;
void create() {
	set( "short", "克雷雅" );
	set( "owner", "clair" );
	set( "object", ([
		"amount9"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"file10"   : "/obj/gift/shenliwan",
		"amount4"  : 1,
		"file1"    : "/obj/gift/shenliwan",
		"file9"    : "/open/gblade/obj/sa-head",
		"amount7"  : 1,
		"amount1"  : 1,
		"file7"    : "/open/gblade/obj/sa-head",
		"amount5"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/ghost-hole/obj/light-spirit",
		"file8"    : "/obj/gift/shenliwan",
		"file3"    : "/obj/gift/shenliwan",
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
	]) );
	set( "build", 24033 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/ou-cloud-club/room/room533",
	]) );
	set( "long", @LONG
這裡是CF中克雷雅的研究室,裡面放的都是關於阿斯拉的研
究資料，別小看這些資料喔,裡面可是紀錄了從阿斯拉一開始的
車身資料到後來的AKF-0的所有資料喔，可見克雷雅的能力真是
厲害，難怪風見可以開到這麼好的車。

LONG);
	setup();
	replace_program(ROOM);
}
