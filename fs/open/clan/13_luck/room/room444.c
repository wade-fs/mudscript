inherit ROOM;
void create() {
	set( "short", "『大牢底部』" );
	set( "owner", "joy" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room445",
	]) );
	set( "long", @LONG

     走到這裡你已經聽不太清楚慘叫聲了，不過你覺得腳下濕濕的，哇！！
 原來這裡是一個水牢，你不禁覺得奇怪，是多大的罪才會被關在這裡，你仔
 細一看，水牢裡關著一個披頭散髮的人看他滿頭白髮，你心想他大概年紀不
 小吧，年紀這麼大的人會犯什麼罪呢？而被關在這恐怖的水牢，只見他四肢
 都被鐵鍊鎖著，仔細看他的眼睛，竟然是金黃色的，通常只有法術很高的人
 才能練成火眼金睛，不過墨教怎麼會有這種人，你不妨問他看看就知道了。

LONG);
	setup();
	replace_program(ROOM);
}
