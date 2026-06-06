// Room : /open/clan/demon_castle/room/room10.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "no_clean_up", 0 );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	set( "short", "魔˙血池林" );
	set( "light_up", 1 );
	set( "long", @LONG

    這裡是惡魔城內的血池林，亦是武林老一輩人口中的江湖禁地，
相傳在數十年前武林中出現了一位武功極為高強的御劍飛龍傅劍寒，
統領著二尊者、四霸王、八魔使為了理想而戰遍大江南北未逢敵手，
數年前成立惡魔城後大惡魔傅劍寒便率領其下隱居於此，專心的修練
武學之最高境界，豈知近年內武林中紛亂不休，群強爭霸，而隱居於
血池林內的眾高手是否會因此而再度踏上血腥之路。

LONG);
	set( "exits", ([ /* sizeof() == 2 */
  "down" : "/open/clan/demon_castle/room/room5",
  "east" : "/open/clan/demon_castle/room/room11.c",
]) );
	set( "clan_room", "惡魔城" );
	setup();

	}
