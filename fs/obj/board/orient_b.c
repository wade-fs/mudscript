inherit BULLETIN_BOARD;
void create()
{
	set_name( "煙雨江南佈告欄", ({ "board", "board" }) );
	set( "long", "煙雨江南佈告欄。\n" );
	set( "board_id", "orient" );
	set( "capacity", 100 );
	set( "location", CLAN_D->clan_query( "orient", "home" ) );
	set( "master", ({ CLAN_D->clan_query( "orient", "master" ) }) );
	setup();
}
