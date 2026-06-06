inherit ROOM;
void create() {
	set( "short", "西長廊" );
	set( "owner", "roarii" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room572",
	]) );
	set( "long", @LONG
這裡是西長廊的盡頭轉角，只見你面前的壁上掛著一幅詩畫，
陽光從壁上方的方格木窗灑落，使你有一種清爽的感覺。往樓梯走
上去便是本樓弟子和師尊的寢居了。前方的餐廳傳來陣陣的飯菜香
，令你肚子餓的不自主的走去。
LONG);
	setup();
	replace_program(ROOM);
}
