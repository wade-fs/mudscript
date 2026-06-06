inherit ROOM;
void create() {
	set( "short", "$HIC$天堂$HIR$中庭$NOR$" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/new_heaven/room/room9",
	]) );
	set( "long", @LONG
這裡是新天堂的中庭入口, 有著一個古意的大門, 旁邊還有
兩個石雕的天使像, 你可以看到前面不遠處有個紫色的噴泉, 那
似乎就是新天堂的第一景, $HIM$紫泉流水$NOR$了
LONG);
	setup();
	replace_program(ROOM);
}
