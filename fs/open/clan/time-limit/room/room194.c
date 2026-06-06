inherit ROOM;
void create() {
	set( "short", "$HIR$幫主$HIY$丹藥$HIM$房2$NOR$" );
	set( "owner", "auo" );
	set( "object", ([
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 500,
		"file1"    : "/open/mon/obj/mon-pill",
		"amount2"  : 1,
		"amount1"  : 1500,
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"amount5"  : 500,
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"amount6"  : 500,
	]) );
	set( "build", 10064 );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room195",
	]) );
	set( "long", @LONG
這裡也是幫主的丹藥房,不過這些丹藥不是用來療傷,而是有其他的功用,例如百花
清心露可以消除大部份的異常狀態,八卦定魂丹可以招喚或是去除惡靈的糾纏,聚靈
丹可以增加靈力,對於幻夢之翼的使用非常有幫助,還有龍王精元可以暫時將烈焰之
氣聚集在雙掌上以增加攻擊力,這些丹藥都有助於練功

LONG);
	setup();
	replace_program(ROOM);
}
