// Room : /open/clan/sky-wu-chi/room/room77.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "clan_room", "天道無極" );
	set( "short", "天蘿密林" );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "long", @LONG
只見東南西北都有小徑，卻不知走向哪一處好。你走了一陣
，似覺又回到了原地。陰陽開闔、乾坤倒置之妙，這一迷路，若
是亂闖，定然只有越走越糟。四下裡寂靜無聲，竟不見半個人影
。你焦急起來，躍上樹巔，四下眺望，南邊是海，向西是光禿禿
的岩石，東面北面都是花樹，五色繽紛，不見盡頭，只看得你頭
暈眼花。

LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/sky-wu-chi/room/room98.c",
  "west" : "/open/clan/sky-wu-chi/room/room38",
]) );
	set( "cmkroom", 1 );
	setup();

	}
