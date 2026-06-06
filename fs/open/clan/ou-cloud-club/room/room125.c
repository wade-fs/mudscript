inherit ROOM;
void create() {
	set( "short", "$HIC$冰風谷$NOR$" );
	set( "object", ([
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"file3"    : "/open/magic-manor/obj/wood-ball",
		"amount5"  : 1,
		"amount7"  : 1,
		"amount1"  : 1,
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount3"  : 1,
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount6"  : 1,
		"amount10" : 1,
		"file6"    : "/open/magic-manor/obj/fire-ball",
		"amount2"  : 1,
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount8"  : 1,
		"amount9"  : 1,
	]) );
	set( "build", 10193 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room166.c",
		"west"      : "/open/clan/ou-cloud-club/room/room202",
		"north"     : "/open/clan/ou-cloud-club/room/room135.c",
	]) );
	set( "long", @LONG
陣陣寒風打在臉上，你不禁將身上的衣服拉得更緊了，放眼
望去盡是一片雪白，冰雪帝王『希瓦』掌管之處雖然環境嚴苛，
但鍛鍊出來的卻也是更堅毅的戰士，心裡頭浮現一個微小的聲音
問道：『你在追求什麼？』，你緩緩的吐了一口氣，熱氣在空氣
中瞬間凝結成一縷白煙，堅定的回答：『天堂之門』‧

左邊是硬皮(peasant)的房間，右邊則是小懶蟲(scs)的小懶窩。

LONG);
	setup();
	replace_program(ROOM);
}
