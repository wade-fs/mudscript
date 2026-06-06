inherit ROOM;
void create() {
	set( "short", "五大夫松" );
	set( "owner", "poll" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room604",
	]) );
	set( "long", @LONG
相傳當年秦始皇上泰山，來到這裏下起雨來，他就到兩棵松樹
底下避雨，結果沒淋著。因此，他就封這兩棵松樹為「五大夫」。
後來不知從哪裏來了一塊巨大的飛來石把兩棵松樹砸死了。後人再
在旁補種五株松樹。在不遠處還有一個禦帳坪，據說就是秦始皇當
年結帳的位置。從這裏再往山上走便會到達十八盤的入口。
LONG);
	setup();
	replace_program(ROOM);
}
