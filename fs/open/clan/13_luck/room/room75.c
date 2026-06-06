inherit ROOM;
void create() {
	set( "short", "混世間二房" );
	set( "object", ([
		"amount2"  : 1,
		"file2"    : "/daemon/class/bonze/puty_pullium",
	]) );
	set( "owner", "adeyzit" );
	set( "build", 10113 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room104",
		"south"     : "/open/clan/13_luck/room/room71",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

　　來到林口華亞科園大門，進去看到那有如老兵一樣爽的華亞警衛
在走進去看到有如魔鬼般的海軍陸戰隊廣達，在往前走將會看到有如
陸軍精誠連的神達，旁邊有一間很大的神達EMCLAB營區，我就在裡面
當著最菜的助工二兵，一部部不起眼卻有如天價的儀器槍械跟一大堆
身價不凡的破銅爛鐵裝備，天天拿著他們去刺槍保養跑三千，這就是
我的家，我的營區。

LONG);
	setup();
	replace_program(ROOM);
}
