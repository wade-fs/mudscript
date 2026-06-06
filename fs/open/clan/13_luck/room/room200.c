inherit ROOM;
void create() {
	set( "short", "龍窟" );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/13_luck/room/room199",
		"down"      : "/open/clan/13_luck/room/room201.c",
	]) );
	set( "long", @LONG

　　經歷過無數的戰鬥你終於來到了『龍窟』，此地正是塵界九龍中
的龍珠－銀羽飛燕，他身後的階梯看來就是維一的通道了，眼看四週
有這不少骸骨，看來已有不少人死在此地了，不知道你是否有能力打
敗銀羽飛燕，繼續往前進，還是會成為下一個亡魂。

LONG);
	setup();
	replace_program(ROOM);
}
