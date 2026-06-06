// Room : /open/clan/ou-cloud-club/room/room36.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$惡魔城 $HIR$入口$NOR$" );
	set( "build", 10017 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "long", @LONG
穿越一大片崎嶇的森林山路之後,你來到了惡魔城的大門之前,
古老生鏽的門把,赫然有幾處鏽斑脫落的部分,看來仍有人能不懼於
邪惡力量的闖進此城,直覺告訴你,若沒有一身驚人藝業,絕對無法
從此城生還,因為它所給你的壓迫感就是如此的巨大!!
LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
  "southeast" : "/open/clan/ou-cloud-club/room/room35",
  "enter" : "/open/clan/ou-cloud-club/room/room37",
]) );
	set( "no_transmit", 1 );
	set( "clan_room", "傲雲山莊" );
	setup();

	}
