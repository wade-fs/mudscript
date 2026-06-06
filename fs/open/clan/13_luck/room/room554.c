inherit ROOM;
void create() {
	set( "short", "最佳時間(1)" );
	set( "owner", "dfyw" );
	set( "object", ([
		"file2"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount2"  : 24,
		"amount1"  : 105,
		"file1"    : "/open/mogi/castle/obj/sspill",
	]) );
	set( "build", 10024 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room548",
	]) );
	set( "long", @LONG
唸書的最佳時間
早上醒來頭腦一定會昏昏的，但去洗把臉後，就會清醒多了，這時
也是頭腦最清醒的時候，而在此時唸書或是記東西都會比較容易！
運動的最佳時間
在早晨的時候出去散散步是不錯的，因為早晨的空氣是最新鮮的，
在散步時多呼吸些清新的空氣，不僅可以提神，對身體又很有幫助，
但切記不要做劇烈運動喔！
LONG);
	setup();
	replace_program(ROOM);
}
