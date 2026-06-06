inherit ROOM;
void create() {
	set( "short", "$HIG$魔法史$HIM$教室$NOR$" );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room59",
		"west"      : "/open/clan/time-limit/room/room36",
	]) );
	set( "long", @LONG
魔法史是學生公認最無聊的一堂課,丙斯教授是個幽靈,用著平板無奇
的語調述說魔法世界的歷史,只要十分鐘就能讓學生陷入嚴重的昏迷狀態,
而丙斯教授從來不改變上課方式,於是這堂課常常被學生用來補眠,
不然就是複習其他功課,似乎只有妙麗能夠專心上完整堂課

LONG);
	setup();
	replace_program(ROOM);
}
