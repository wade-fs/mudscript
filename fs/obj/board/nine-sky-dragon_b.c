inherit BULLETIN_BOARD;
void create()
{
	set_name( "九天蒼龍佈告欄", ({ "board", "board" }) );
	set( "long", "九天蒼龍佈告欄。\n" );
	set( "board_id", "nine-sky-dragon" );
	set( "capacity", 100 );
	set( "location", CLAN_D->clan_query( "nine-sky-dragon", "home" ) );
	set( "master", ({ CLAN_D->clan_query( "nine-sky-dragon", "master" ) }) );
	setup();
}
