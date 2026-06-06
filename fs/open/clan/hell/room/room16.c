inherit ROOM;
void create() {
	set( "short", "$RED$貓森林$NOR$" );
	set( "build", 1124 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room12",
	]) );
	set( "long", @LONG
在這茂竹的森林裡，出口並不特別明顯，前方的路到底通往那裡呢？
疑？地上有一塊$HIW$大石頭$NOR$(stone)，上面的字似乎正警告著路人
四週望去，樹幹上都被一些招式所傷，從招式的形狀和深度看南，
都是被內力極深的高手所傷，莫非是傳說的$RED$霹靂貓$NOR$嗎？
或許四處找找能有所收獲吧！！

　　　　　 $HIW$喵～　喵～　$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
