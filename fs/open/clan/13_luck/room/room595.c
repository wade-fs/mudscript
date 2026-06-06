inherit ROOM;
void create() {
	set( "short", "刑天樓書房 " );
	set( "light_up", 1 );
	set( "owner", "roarii" );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room596",
	]) );
	set( "long", @LONG
現在你來到了聖堂堂主的書房，在這裡堆滿了各式各樣
的書籍。此外，在這裡的書桌前坐著一名正在寫毛筆的人，
看樣子好像是一位飽讀詩書的書生。不過仔細一看他身上揹
著一把如槍似筆的武器，難道他就是聖堂四守的聖˙文采！
如果是的話，請你不要惹他！他看起來雖然是一名書生，功
夫卻也是一等一的高手。

LONG);
	setup();
	replace_program(ROOM);
}
