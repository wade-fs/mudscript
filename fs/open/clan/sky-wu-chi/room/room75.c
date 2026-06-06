// Room : /open/clan/sky-wu-chi/room/room75.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
	set( "short", "$HIC$DABBIE的玄關$NOR$" );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"south"     : "/open/clan/sky-wu-chi/room/room144.c",
		"north"     : "/open/clan/sky-wu-chi/room/room152.c",
	]) );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "build", 12001 );
	set( "object", ([
		"amount10" : 1,
		"amount6"  : 1,
		"file4"    : "/u/a/acky/obj/gps",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"file8"    : "/open/ping/questsfan/obj/diamond_legging",
		"amount9"  : 1,
		"file6"    : "/open/dancer/obj/yuawaist",
		"file9"    : "/open/ping/questsfan/obj/diamond_hairpin",
		"file5"    : "/open/ping/questsfan/obj/diamond_boots",
		"amount8"  : 1,
		"file1"    : "/open/capital/guard/gring",
		"file10"   : "/open/killer/weapon/k_torch",
		"file7"    : "/open/ping/questsfan/obj/diamond_skirt",
		"amount7"  : 1,
	]) );
	set( "long", @LONG
你走到了一個名為『青龍』走廊的地方，你發現這裡的地板有些許的不同
因為這裡的地方刻著數條惡龍，你數了一數結果共有九隻龍，你在看了一下子
發現有一隻龍跟其他的不一樣，心裡也就想著，嗯，看來這隻必定是整個裡面
的頭頭，你低下去撫摸了一下，結果發現這種的眼睛居然爆射出一道光芒，突
然間你嚇了一跳。此時這條惡龍就像是活了過來一樣，向著你迎面撲來，你覺
的惡龍的來勢兇兇，集忙運起了你百分之一百二十的力量想要抵禦惡龍的攻擊
可是當你正想舉手起來擋的時後，你已經來不及了，因為他的尾巴正掃到你的
身體。

LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	set( "clan_room", "天道無極" );
	setup();

	}
