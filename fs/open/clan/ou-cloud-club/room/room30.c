// Room : /open/clan/ou-cloud-club/room/room30.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIY$西方極樂 $HIW$天竺$NOR$" );
	set( "object", ([
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount7"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"amount8"  : 1,
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount3"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount5"  : 1,
	]) );
	set( "build", 10185 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "long", @LONG
你來到了一座炎熱的城市,這裡的人們由於長期曝曬於烈日中
的關係,皮膚都比我們黑得多,而且各種佛教寺廟林立,原來,這裡
就是佛教的發源地--天竺,傳聞佛教乃天竺之國教,果然傳言不虛
,一路上處處可見身劈袈裟的僧侶,令人感到濃厚的宗教氣息.
LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"east"      : "/open/clan/ou-cloud-club/room/room29",
		"west"      : "/open/clan/ou-cloud-club/room/room31.c",
]) );
	set( "no_transmit", 1 );
	set( "clan_room", "傲雲山莊" );
	setup();

	}
