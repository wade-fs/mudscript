inherit BULLETIN_BOARD;
void create()
{
	set_name( "遠古神木", ({ "ancient tree", "board" }) );
	set( "long", "幽暗密林佈告欄。\n" );
	set( "board_id", "dark-forest" );
	set( "capacity", 100 );
	set( "location", CLAN_D->clan_query( "dark-forest", "home" ) );
	set( "master", ({ CLAN_D->clan_query( "dark-forest", "master" ) }) );
	setup();
}
