inherit ROOM;
void create() {
	set( "short", "$HIC$劍神界$NOR$-御善防" );
	set( "object", ([
		"file5"    : "/obj/stone/powder",
		"amount5"  : 4,
	]) );
	set( "build", 10637 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/hell/room/room13",
		"east"      : "/open/clan/hell/room/room57",
	]) );
	set( "long", @LONG
一進到這裡就看到滿桌的食物，讓人想抓一把來吃
不過一想到這裡是地府，心想這裡的東西能吃嗎。。。
但眼前一片美食，你怎會放手讓他走呢，往桌上一看，
上面擺的是。。。

    $HIR$血腥瑪莉$NOR$(Blood drink)
    $HIR$人肉肉包$NOR$(Human dumpling)
LONG);
	setup();
	replace_program(ROOM);
}








