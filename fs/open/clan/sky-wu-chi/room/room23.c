// Room : /open/clan/sky-wu-chi/room/room23.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
	set( "long", @LONG
從走道轉進到這裡，你覺得空間好像變的十分狹窄。忽然你看到一扇小小門，
上面寫著八個小小字◎◎歡迎來到小小世界◎◎。你好奇的打開門往裡頭瞧去，裡
面漆黑一片，也看不清楚出口，你試著弄出一些光亮，卻隨即被黑暗吞噬，可是恐
懼之心終究敵不過好奇的力量，所以把身上多餘的東西放在小小門旁邊的櫃子裡，
鼓起勇氣，向著未知的通道走進去．．．

                $BLU$→ → →   ██▇▇▆▆▅▅▄▄    → → →$NOR$

驟然的光亮讓你一時無法接受，但是隨即你發現身邊的東西彷彿都小了好幾號，似
乎來到了孩童的世界一般，果然是小小世界。

LONG);
	set( "short", "$HIW$【小小世界入口】$NOR$" );
	set( "owner", "peiyi" );
	set( "object", ([
		"file10"   : "/open/mon/obj/ghost-cloak",
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"file1"    : "/open/killer/obj/k_ring",
		"file4"    : "/open/scholar/obj/icefan",
		"amount8"  : 1,
		"file2"    : "/daemon/class/bonze/puty_pullium",
		"amount1"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
		"amount9"  : 1,
		"amount4"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"file9"    : "/daemon/class/fighter/armband",
		"file3"    : "/open/mon/obj/ghost-helmet",
		"amount5"  : 1,
		"file8"    : "/open/mon/obj/ghost-legging",
		"file7"    : "/open/dancer/obj/yuawaist",
		"amount2"  : 1,
		"file6"    : "/open/dancer/obj/maple_ribbon",
	]) );
	set( "build", 10175 );
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"enter"     : "/open/clan/sky-wu-chi/room/room74.c",
		"west"      : "/open/clan/sky-wu-chi/room/room12.c",
]) );
	set( "no_clean_up", 0 );
	set( "clan_room", "天道無極" );
	set( "no_transmit", 1 );
	setup();

	}
