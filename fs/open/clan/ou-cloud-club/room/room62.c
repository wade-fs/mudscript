// Room : /open/clan/ou-cloud-club/room/room62.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$惡魔城$HIR$時計ソ廊$NOR$" );
	set( "build", 3058 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 1 */
  "westdown" : "/open/clan/ou-cloud-club/room/room57",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "long", @LONG
你攀登上來之後,發現這裡只是個空曠的房間,角落散佈著
幾個空無一物的寶箱,看來是來晚嘍, 但也因這次的落空使你
意識到,在這作城裡調查的人類,應該不僅你一人,這位搶在前
頭開得寶箱的人,其動機為何,值得思考,或許能成為合作的夥
伴吧!!
LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
