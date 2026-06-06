// Room : /open/clan/ou-cloud-club/room/room14.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "no_clean_up", 0 );
	set( "no_transmit", 1 );
	set( "clan_room", "傲雲山莊" );
	set( "light_up", 1 );
	set( "exits", ([ /* sizeof() == 4 */
		"north"     : "/open/clan/ou-cloud-club/room/room118",
		"west"      : "/open/clan/ou-cloud-club/room/room107.c",
		"east"      : "/open/clan/ou-cloud-club/room/room130.c",
		"south"     : "/open/clan/ou-cloud-club/room/room15.c",
]) );
	set( "cmkroom", 1 );
	set( "short", "$HIC$冰風之谷$NOR$" );
	set( "object", ([
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount3"  : 1,
		"amount7"  : 1,
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount10" : 1,
		"amount6"  : 1,
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount9"  : 1,
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"file9"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount5"  : 1,
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount8"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"amount4"  : 1,
	]) );
	set( "build", 10357 );
	set( "long", @LONG
陣陣寒風打在臉上，你不禁將身上的衣服拉得更緊了，放眼
望去盡是一片雪白，冰雪帝王『希瓦』掌管之處雖然環境嚴苛，
但鍛鍊出來的卻也是更堅毅的戰士，心裡頭浮現一個微小的聲音
問道：『你在追求什麼？』，你緩緩的吐了一口氣，熱氣在空氣
中瞬間凝結成一縷白煙，堅定的回答：『天堂之門』‧

左邊是刀邪．不二刀(moblade)的房間，右邊則是無情(koi)之臥室．

LONG);
	setup();

	}
