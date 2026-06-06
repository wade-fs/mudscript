inherit ROOM;
void create() {
	set( "short", "非洲野外籠" );
	set( "owner", "kid" );
	set( "object", ([
		"file1"    : "/open/magic-manor/obj/lunar-heart",
		"amount3"  : 108,
		"amount5"  : 1,
		"amount2"  : 1,
		"file5"    : "/open/magic-manor/obj/lunar-heart",
		"amount1"  : 1,
		"file6"    : "/open/magic-manor/obj/lunar-heart",
		"amount8"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"file8"    : "/open/poison/obj/armband1",
		"file7"    : "/obj/gift/hobowdan",
		"file3"    : "/open/fire-hole/obj/g-pill",
	]) );
	set( "exits", ([
		"out"       : "/open/clan/ou-cloud-club/room/room121",
		"add"       : "/open/clan/ou-cloud-club/room/room356",
	]) );
	set( "light_up", 1 );
	set( "build", 11342 );
	set( "long", @LONG

    轟隆轟隆的轉動聲此起彼落,令你好奇的睜大了眼睛四處張望,哇~~~~
赫然發現這裡擺了好多個滾輪,其中有些正不停地轉動著,而滾輪之中,更藏
著一隻隻可愛的楓葉鼠!!加卡利亞,坎培爾,羅勃夫斯基...各種你想得到的
品種都可以在這裡看到,而這些小傢伙一看到你這個陌生人來到這邊,也好奇
的停下手邊的事,眼睛睜得大大的盯著你瞧,但不久之後,又開始跑滾輪的跑
滾輪,吃東西的吃東西了,看來他們的主人必定很細心照顧及訓練他們,才能
讓他們如此的有安全感.

LONG);
	setup();
	replace_program(ROOM);
}
