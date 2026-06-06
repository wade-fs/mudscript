inherit ROOM;
void create() {
	set( "short", "滄海粟" );
	set( "owner", "mill" );
	set( "build", 10080 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room131.c",
	]) );
	set( "long", @LONG

    曾經有段美好的戀情，擺在我的眼前，
          但我卻不懂的珍惜，等到失去後，才後悔莫及。
               
               如果時光可以倒流，我會跟她說我愛你，
                   假如非要在這上面灌上個期限，我希望那是 ~ 一萬年 ~。

一段戀情最難過的是沒有好好珍惜，等到想挽回已經來不及了，分手或許
能找到新戀情，但是在這廣大的世界裡，那裡找的到曾經為你付出一切，
為你神昏顛倒的同一個女人，結束後，多想想今後的旅程吧。

LONG);
	setup();
	replace_program(ROOM);
}
