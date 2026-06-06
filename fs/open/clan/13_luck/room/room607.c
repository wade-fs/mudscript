inherit ROOM;
void create() {
	set( "short", "「大驛道」" );
	set( "owner", "mill" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room606",
		"south"     : "/open/clan/13_luck/room/room608",
	]) );
	set( "long", @LONG
    你走在一條塵土飛揚的大驛道上。四周人來人往。挑擔子的
行商，趕著大車的馬夫，上京趕考的書生，熙熙攘攘，非常熱鬧。
不時還有兩三騎快馬從身邊飛馳而過，揚起一路塵埃。馬上的人
個個身著勁裝，衣甲鮮明，有的還隨身佩帶著刀劍。看來都是些
些習武的江湖人。道路兩旁是整整齊齊的楊樹林。
LONG);
	setup();
	replace_program(ROOM);
}
