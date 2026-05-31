inherit BULLETIN_BOARD;
void create()
{
	set_name( "逍遙聖境佈告欄", ({ "board", "board" }) );
	set( "long", "逍遙聖境佈告欄。\n" );
	set( "board_id", "free-zone" );
	set( "capacity", 100 );
	set( "location", CLAN_D->clan_query( "free-zone", "home" ) );
	set( "master", ({ CLAN_D->clan_query( "free-zone", "master" ) }) );
	setup();
}
