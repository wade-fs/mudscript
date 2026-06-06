inherit ROOM;
void create() {
	set( "short", "斷魂橋" );
	set( "object", ([
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
	]) );
	set( "owner", "mwf" );
	set( "build", 10026 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room414",
		"south"     : "/open/clan/13_luck/room/room416.c",
	]) );
	set( "long", @LONG

    這是一座不大不小的木橋，橋底卻沒有流水的聲音，橋墩兩旁造著幾
個隱密的碉堡，裡頭可以藏多少人在這裡卻看不出來，橋的形狀有點奇怪
，兩頭很寬，中間卻很狹窄，似乎刻意用來圍殺敵人之用，被逼到橋中心
的人想必連拳腳都施展不開，看來得要快速通過才行。


          .        .           .              ~~~~      ★.
      .               . ☆    .         .       ~~~~     .     .   .
          .      .             .          .   ~~~~   ~~~~        .
     ▁▂▃▄█▄▅▄▄▄▅▆█▆▃▅▆▆▅██▅▆▆▅█▆▅▄▄▃▃▂▂▁ 


LONG);
	setup();
	replace_program(ROOM);
}
