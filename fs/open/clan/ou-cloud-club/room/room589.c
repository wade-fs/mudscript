inherit ROOM;
void create() {
	set( "short", "五轉聚靈珠" );
	set( "build", 60 );
	set( "owner", "roboii" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room539",
	]) );
	set( "long", @LONG
$HIC$五五五五五五五五五五五五五五五五五五五五五五五五
　　轉轉轉轉轉轉轉轉轉轉轉轉轉轉轉轉轉轉轉轉轉轉轉轉
　　$HIW$聚聚聚聚聚聚聚聚聚聚聚聚聚聚聚聚聚聚聚聚聚聚聚聚
　　$HIY$靈靈靈靈靈靈靈靈靈靈靈靈靈靈靈靈靈靈靈靈靈靈靈靈
　　珠珠珠珠珠珠珠珠珠珠珠珠珠珠珠珠珠珠珠珠珠珠珠珠
$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
