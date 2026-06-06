inherit ROOM;
void create() {
	set( "short", "$YEL$明日土行陣$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"file1"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount1"  : 1,
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
	]) );
	set( "build", 13783 );
	set( "owner", "tomorrow" );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room740",
	]) );
	set( "long", @LONG
這裡是tomorrow所排設的五行陣之一  土行陣
滾滾黃沙  四周沒有一草一木  景色是如此的荒涼
在沙漠中  體力一點一滴的流失  你忽然發現自己正在往下沉
你拼命的掙扎想逃離  無耐流沙已慢慢將你吞沒  只剩下一隻手在地表上
這裡是tomorrow所排設的五行陣之一  土行陣
滾滾黃沙  四周沒有一草一木  景色是如此的荒涼
在沙漠中  體力一點一滴的流失  你忽然發現自己正在往下沉
你拼命的掙扎想逃離  無耐流沙已慢慢將你吞沒  只剩下一隻手在地表上
LONG);
	setup();
	replace_program(ROOM);
}
