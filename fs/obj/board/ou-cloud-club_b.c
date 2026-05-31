inherit BULLETIN_BOARD;
void create()
{
	set_name( "傲雲山莊佈告欄", ({ "board", "board" }) );
	set( "long", "傲雲山莊佈告欄。\n" );
	set( "board_id", "ou-cloud-club" );
	set( "capacity", 100 );
	set( "location", CLAN_D->clan_query( "ou-cloud-club", "home" ) );
	set( "master", ({ CLAN_D->clan_query( "ou-cloud-club", "master" ) }) );
	setup();
}
