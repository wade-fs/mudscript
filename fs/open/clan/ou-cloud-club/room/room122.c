// Room : /open/clan/ou-cloud-club/room/room122.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 4 */
		"west"      : "/open/clan/ou-cloud-club/room/room123.c",
		"south"     : "/open/clan/ou-cloud-club/room/room118.c",
		"north"     : "/open/clan/ou-cloud-club/room/room16.c",
		"east"      : "/open/clan/ou-cloud-club/room/room631",
]) );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	set( "clan_room", "傲雲山莊" );
	set( "long", @LONG
巨大的身形矗立在遠方，遠古的力量之神『泰坦』正守護著
這裡，寬闊的背影讓人心中湧現一股安定的感覺，你不禁想著要
盡快變強能夠去守護別人，隨手抓起一把泥土灑向空中，霎時間
變成無數的光點落在你的身上，一股莫名的力量在體內湧現。

左邊是火燄女皇小Ｐ(ppp)的家，右邊則是閒雲野鶴(andyabc)之發呆房．

LONG);
	set( "light_up", 1 );
	set( "short", "$HIY$地震之帶$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount7"  : 1,
		"amount8"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount9"  : 1,
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "build", 10396 );
	setup();

	}
