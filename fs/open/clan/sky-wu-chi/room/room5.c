inherit ROOM;
void create() {
	set( "short", "$HIC$交誼室$NOR$" );
	set( "build", 26 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room2",
		"up"        : "/open/clan/sky-wu-chi/room/room7.c",
		"down"      : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG
這裡是天道無極幫下幫眾所休息，閒聊的場所，
要是你覺得累了,可以在此地稍做休息,與人聊一聊天
,大家都會很歡迎你的.不論你是新幫眾或是老一輩的
玩家，在此休息絕對是你最佳的選擇。除了休息。往
上也是通往幫中人員房間的道路。

LONG);
	setup();
	replace_program(ROOM);
}
