inherit ROOM;
void create() {
	set( "short", "$HBCYN$天晶結界$NOR$" );
	set( "owner", "neun" );
	set( "light_up", 1 );
	set( "build", 10349 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room29",
	]) );
	set( "long", @LONG
傳說中書生最好的裝備,虹晶裝備全套,雖然是針對書生設計的,但其實對於其他
門派來說,其實也是不錯的防身裝備.所以幫主平時特別準備三套此種裝備,置於此結
界中,讓幫眾在偷懶或是緊急的時候可以來此拿取,結界的頂端刻著幫主的叮嚀,希望
幫眾使用完後都能自動歸還

LONG);
	setup();
	replace_program(ROOM);
}
