// Room : /open/clan/ou-cloud-club/room/room83.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "朵麗雅的水世界" );
	set( "owner", "turtle" );
	set( "object", ([
		"amount10" : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/magic-manor/obj/lunar-heart",
		"file2"    : "/open/magic-manor/obj/lunar-heart",
		"file7"    : "/open/magic-manor/obj/sun-heart",
		"amount2"  : 1,
		"file1"    : "/open/magic-manor/obj/sun-heart",
		"amount6"  : 1,
		"file8"    : "/open/magic-manor/obj/lunar-heart",
		"file6"    : "/open/magic-manor/obj/lunar-heart",
		"file4"    : "/open/magic-manor/obj/sun-heart",
		"amount9"  : 1,
		"file3"    : "/open/magic-manor/obj/sun-heart",
		"amount8"  : 1,
		"file10"   : "/open/magic-manor/obj/lunar-heart",
		"amount1"  : 1,
		"file9"    : "/open/magic-manor/obj/sun-heart",
		"amount5"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10532 );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room744.c",
		"south"     : "/open/clan/ou-cloud-club/room/room740.c",
		"down"      : "/open/clan/ou-cloud-club/room/room743",
		"north"     : "/open/clan/ou-cloud-club/room/room417.c",
		"west"      : "/open/clan/ou-cloud-club/room/room741.c",
		"east"      : "/open/clan/ou-cloud-club/room/room742",
	]) );
	set( "no_clean_up", 0 );
	set( "long", @LONG
一走近這裏，迎面吹來清涼的水珠，沁涼的氣息使你全身暢快，一片
蔚藍色的世界，透明的氣泡在水中浮浮沈沈，鮮紅墨綠的海草隨著波浪起伏
左右擺動，搖曳生姿，五彩繽紛的魚類在珊瑚礁群中迴游穿梭，肥腴潤澤的
五角海星在海底緩緩蠕動，伸長了有鋸齒邊緣的觸手探測著四周，珊瑚礁旁
躺著些大小貝殼，有渦漩紋的大海螺，也有扇貝微微開闔著的蚌。
LONG);
	set( "cmkroom", 1 );
	set( "clan_room", "傲雲山莊" );
	set( "no_transmit", 1 );
	setup();

	}
