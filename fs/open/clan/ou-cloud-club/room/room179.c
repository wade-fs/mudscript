inherit ROOM;
void create() {
	set( "short", "幸福的泉源" );
	set( "object", ([
		"file8"    : "/open/ping/obj/cloud",
		"amount6"  : 1,
		"amount3"  : 1105,
		"file5"    : "/open/doctor/item/sick_item",
		"amount1"  : 1082,
		"amount5"  : 793,
		"file2"    : "/open/doctor/item/ground_item",
		"amount4"  : 45,
		"file4"    : "/open/doctor/item/ff_item",
		"amount8"  : 1,
		"amount2"  : 1071,
		"file6"    : "/open/ping/obj/cloud",
		"file1"    : "/open/doctor/item/human_item",
		"file3"    : "/open/doctor/item/sky_item",
		"file7"    : "/open/ping/obj/cloud",
		"amount7"  : 1,
	]) );
	set( "owner", "adgsii" );
	set( "light_up", 1 );
	set( "build", 10121 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room176",
	]) );
	set( "long", @LONG
           你是否曾感受過...那種月明星稀的夜晚...獨自一人在草地上...
     隨著迎面吹來的涼風...有著一股莫名的情愫湧上心頭...這種感覺不是悲傷...
不是孤獨更不是失落...這一份感覺是可以讓你的心...有那麼一點酸酸的有那麼一絲的甜蜜
             愛就是這麼有趣的東西...讓你有著那麼難以言容的幸福感...
                    期待著你我都能沈醉在思念的漩渦裡.....

LONG);
	setup();
	replace_program(ROOM);
}
