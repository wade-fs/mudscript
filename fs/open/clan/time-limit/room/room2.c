inherit ROOM;
void create() {
	set( "short", "$HIR$時$HIG$空$HIY$錢莊$NOR$ " );
	set( "build", 10081 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room178",
		"west"      : "/open/clan/time-limit/room/hall.c",
		"south"     : "/open/clan/time-limit/room/room99.c",
	]) );
	set( "long", @LONG
當初幫主為了進行時空壓縮,花了不少銀兩聘請一流的魔法師,
才有今日的成果,而為了進行更多的時空壓縮,
則需要更多的魔法師參與,也就需要更多的銀兩,
因此設立錢莊是希望能讓幫眾也能貢獻一己之力,參與幫派的建立,
並提升幫眾對幫派的認同感

LONG);
	setup();
	replace_program(ROOM);
}
