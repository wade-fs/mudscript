inherit ROOM;
void create() {
	set( "short", "$HIY$聖$HIM$龍$HIR$口$NOR$" );
	set( "build", 11005 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room203",
		"south"     : "/open/clan/time-limit/room/room200.c",
	]) );
	set( "long", @LONG
聖龍口是道教的聖地,曾經人聲鼎沸,也曾經門可羅雀,不過最近聖龍口的爐火被三世道
君點燃,此爐火噴出萬丈火花,有如峰火台的峰火,傳遞出訊息,使得無以計數的道眾蜂
擁至聖龍口,看來是有大事發生了,三世道君宣佈以歸元聖童為領導,集元師太領軍,準
備對某件事採取行動了

LONG);
	setup();
	replace_program(ROOM);
}
