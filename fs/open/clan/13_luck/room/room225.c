inherit ROOM;
void create() {
	set( "short", "龍窟" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room224",
		"down"      : "/open/clan/13_luck/room/room226",
	]) );
	set( "long", @LONG

　　經歷過無數的戰鬥你終於來到了『龍窟』，此地正是塵界九龍中
的龍末－龍末九，他身後的階梯看來就是唯一的通道了，眼看四週有
這不少骸骨，看來已有不少人死在此地了，不知道你是否有能力打敗
龍末九，繼續往前進，還是會成為下一個亡魂。 

LONG);
	setup();
	replace_program(ROOM);
}
