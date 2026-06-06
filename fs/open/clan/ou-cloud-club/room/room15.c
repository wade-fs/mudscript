// Room : /open/clan/ou-cloud-club/room/room15.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "no_clean_up", 0 );
	set( "light_up", 1 );
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 3 */
		"north"     : "/open/clan/ou-cloud-club/room/room14.c",
		"east"      : "/open/clan/ou-cloud-club/room/room148",
		"west"      : "/open/clan/ou-cloud-club/room/room17.c",
		"south"     : "/open/clan/ou-cloud-club/room/room135.c",
]) );
	set( "long", @LONG
陣陣寒風打在臉上，你不禁將身上的衣服拉得更緊了，放眼
望去盡是一片雪白，冰雪帝王『希瓦』掌管之處雖然環境嚴苛，
但鍛鍊出來的卻也是更堅毅的戰士，心裡頭浮現一個微小的聲音
問道：『你在追求什麼？』，你緩緩的吐了一口氣，熱氣在空氣
中瞬間凝結成一縷白煙，堅定的回答：『天堂之門』‧

左邊是紫雲蝶(mekyn)的魔劍塚，右邊則是月中劍(sunsword)的漣漪房．

LONG);
	set( "no_transmit", 1 );
	set( "clan_room", "傲雲山莊" );
	set( "short", "$HIC$冰風谷$NOR$" );
	set( "object", ([
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount3"  : 1,
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount7"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount6"  : 1,
		"amount10" : 1,
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount9"  : 1,
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount5"  : 1,
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount8"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
	]) );
	set( "build", 11157 );
	setup();

	}
