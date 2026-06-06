inherit ROOM;
void create() {
	set( "short", "岩石地" );
	set( "owner", "evonne" );
	set( "build", 10008 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room653",
	]) );
	set( "long", @LONG
滿地都是碎裂的岩石，一年四季都狂刮的狂風讓植物與動物無法在這裡
生存，岩石因為風化而碎裂，遍佈在地上，走在上面不小心都會被尖銳的石
頭割傷，很難行走過這個區域，很難想像妖精族能夠在這種地方生存下來，
或許尋找出它們生存的地方環境，就能解決你心中的疑惑。

LONG);
	setup();
	replace_program(ROOM);
}
