inherit ROOM;
void create() {
	set( "short", "鳳凰樓五樓" );
	set( "build", 12 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room196.c",
		"east"      : "/open/clan/13_luck/room/room231.c",
		"down"      : "/open/clan/13_luck/room/room102.c",
		"west"      : "/open/clan/13_luck/room/room240",
		"north"     : "/open/clan/13_luck/room/room756",
		"up"        : "/open/clan/13_luck/room/room100.c",
	]) );
	set( "long", @LONG

    在店小二的引領，你沿著燈火照亮的樓梯往上爬，來到了鳳凰樓
五樓的通道，往你的廂房走去。從窗口往西邊的窗口望去，那裡是幫
主小南費心建造的『虛擬海洋』，放眼望去一片汪洋大海，一但進入
，想要在出來，那可是要花費好大一番功夫才有辦法找到出口。

LONG);
	setup();
	replace_program(ROOM);
}
