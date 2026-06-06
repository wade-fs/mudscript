inherit ROOM;
void create() {
	set( "short", "$YEL$$HBBLU$阿嚕咪的水族室$NOR$" );
	set( "object", ([
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/obj/master_snake_head",
	]) );
	set( "build", 10632 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room155",
		"west"      : "/open/clan/sky-wu-chi/room/room218.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
$HIG$一進到此地，印入眼廉的是一個超大的$HIB$魚缸$HIG$，原來最近
$HIR$阿嚕米$HIG$喜歡上養魚兒，便特地請人做個一個$HIB$魚缸$HIG$。$HIB$魚缸$HIG$裡各
式各樣的魚兒都有，$HIR$阿嚕米$HIG$在缸裡布置了水草，再搭配上亮
眼的$WHT$日光燈$HIG$，另你不禁心情頓時明亮起來，只覺魚兒在缸裡
的悠閒生活，正對你照成一種安撫之心，每當$HIR$阿嚕米$HIG$有不愉
快之事，他便會來到此地舒解心情。$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
