// Room : /open/clan/ou-cloud-club/room/room16.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
巨大的身形矗立在遠方，遠古的力量之神『泰坦』正守護著
這裡，寬闊的背影讓人心中湧現一股安定的感覺，你不禁想著要
盡快變強能夠去守護別人，隨手抓起一把泥土灑向空中，霎時間
變成無數的光點落在你的身上，一股莫名的力量在體內湧現。

左邊是旎旎(neonn)的家，右邊是阿綺小館(duramax)。

LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "cmkroom", 1 );
	set( "clan_room", "傲雲山莊" );
	set( "short", "$HIY$地震帶$NOR$" );
	set( "object", ([
		"amount4"  : 99999,
		"amount1"  : 99999,
		"file6"    : "/open/killer/obj/bellstar",
		"amount2"  : 99999,
		"file4"    : "/open/killer/obj/bellstar",
		"file5"    : "/open/killer/obj/bellstar",
		"amount9"  : 99999,
		"file7"    : "/open/killer/obj/bellstar",
		"amount3"  : 99999,
		"amount6"  : 99999,
		"file1"    : "/open/killer/obj/bellstar",
		"file2"    : "/open/killer/obj/bellstar",
		"amount5"  : 99999,
		"amount10" : 99999,
		"amount8"  : 34318,
		"file10"   : "/open/killer/obj/bellstar",
		"file8"    : "/open/killer/obj/bellstar",
		"amount7"  : 96458,
		"file3"    : "/open/killer/obj/bellstar",
		"file9"    : "/open/killer/obj/bellstar",
	]) );
	set( "build", 10632 );
	set( "exits", ([ /* sizeof() == 1 */
		"south"     : "/open/clan/ou-cloud-club/room/room122.c",
		"east"      : "/open/clan/ou-cloud-club/room/room249",
		"west"      : "/open/clan/ou-cloud-club/room/room140.c",
		"north"     : "/open/clan/ou-cloud-club/room/room18.c",
]) );
	set( "light_up", 1 );
	setup();

	}
