inherit BULLETIN_BOARD;
void create()
{
	set_name( "陰曹地府佈告欄", ({ "board", "board" }) );
	set( "long", "陰曹地府佈告欄。\n" );
	set( "board_id", "hell" );
	set( "capacity", 100 );
	set( "location", CLAN_D->clan_query( "hell", "home" ) );
	set( "master", ({ CLAN_D->clan_query( "hell", "master" ) }) );
	setup();
}
