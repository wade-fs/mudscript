inherit ROOM;
void create() {
	set( "short", "$HIW$波-冥想房(4)$NOR$" );
	set( "owner", "perth" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room388",
		"south"     : "/open/clan/ou-cloud-club/room/room317.c",
		"east"      : "/open/clan/ou-cloud-club/room/room389",
	]) );
	set( "object", ([
		"amount2"  : 1,
		"file9"    : "/obj/gift/shenliwan",
		"amount3"  : 1,
		"file6"    : "/open/magic-manor/obj/sun-heart",
		"file4"    : "/open/killer/obj/kill_yar_head",
		"amount10" : 1,
		"file8"    : "/open/magic-manor/obj/lunar-heart",
		"file7"    : "/open/magic-manor/obj/sun-heart",
		"amount8"  : 1,
		"amount5"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/killer/obj/kill_yar_head",
		"amount9"  : 1,
		"file5"    : "/obj/gift/xisuidan",
		"amount6"  : 1,
		"file1"    : "/open/gblade/obj/sa-head",
		"amount7"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/killer/obj/kill_yar_head",
		"file10"   : "/obj/gift/hobowdan",
	]) );
	set( "light_up", 1 );
	set( "build", 11190 );
	set( "long", @LONG
牆上泛黃的畫像裡，人似錦、馬如龍，健壯高大的黑
馬上坐的一位十七八歲的少年原來，這是波要提醒自己當
初苦練之歷程因此，每當波在武學上有了阻礙瓶頸之時便
會到此間打坐冥想，以突破自己武學之限制不過隨著波的
年歲增長，武學境界更加提高來此間靜坐的次數是越來越
少了。

  吾    道    一     以     貫     之    ～

LONG);
	setup();
	replace_program(ROOM);
}
