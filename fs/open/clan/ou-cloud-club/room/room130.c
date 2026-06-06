// Room : /open/clan/ou-cloud-club/room/room130.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "clan_room", "傲雲山莊" );
	set( "light_up", 1 );
	set( "exits", ([ /* sizeof() == 1 */
		"east"      : "/open/clan/ou-cloud-club/room/room196.c",
		"west"      : "/open/clan/ou-cloud-club/room/room14",
]) );
	set( "short", "$HIY$無$HIC$情$HIR$一生$NOR$" );
	set( "owner", "flyindance" );
	set( "object", ([
		"file9"    : "/open/mon/obj/ghost-cloak",
		"file7"    : "/open/mon/obj/ghost-legging",
		"file10"   : "/obj/gift/xiandan",
		"file5"    : "/open/dancer/obj/yuawaist",
		"amount10" : 1,
		"file8"    : "/open/mon/obj/ghost-claw",
		"amount2"  : 1,
		"amount7"  : 1,
		"amount9"  : 1,
		"amount8"  : 1,
		"file6"    : "/open/mon/obj/ghost-helmet",
		"file2"    : "/obj/gift/hobowdan",
		"amount6"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 10387 );
	set( "long", @LONG
劍君十二恨的老大〔無情〕的住所，傳聞此人
是幫主在求武時的大哥，武學似乎還在幫主劍君之
上，但卻隱居於此，而此房裝飾更為簡樸，只有一
張床可以用來睡覺跟幾隻拿來練武用的木人佇立著
而已．牆角道是擺著不少武具．

LONG);
	set( "cmkroom", 1 );
	setup();

	}
