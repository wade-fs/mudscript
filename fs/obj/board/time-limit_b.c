inherit BULLETIN_BOARD;
void create()
{
	set_name( "$BRED$時空$BGRN$冒險$BYEL$記$BBLU$錄$BMAG$石$NOR$", ({ "time-stone", "board" }) );
	set( "long", "$BRED$時空$BGRN$冒險$BYEL$記$BBLU$錄$BMAG$石$NOR$\n" );
	set( "board_id", "time-limit" );
	set( "capacity", 100 );
	set( "location", CLAN_D->clan_query( "time-limit", "home" ) );
	set( "master", ({ CLAN_D->clan_query( "time-limit", "master" ) }) );
	setup();
}
