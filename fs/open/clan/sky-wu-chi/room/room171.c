inherit ROOM;
void create() {
	set( "short", "如夢似幻" );
	set( "owner", "cdrom" );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "build", 10137 );
	set( "light_up", 1 );
	set( "long", @LONG
你恍若進入一個飄渺虛無的空間,只覺得快要無法呼吸,你感覺有雙
眼睛正在盯著你看,但是你環顧四周,並沒有任何東西存在,忽然你身形
落空,往下墬落,正當你快要跌落地面之時,你忽然驚醒!發現剛才的一切
只是幻覺,讓你覺得鬆了一口氣.

LONG);
	setup();
	replace_program(ROOM);
}
