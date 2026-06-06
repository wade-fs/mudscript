inherit ROOM;
void create() {
	set( "short", "$HIR$明日火行陣$NOR$" );
	set( "object", ([
		"amount9"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount7"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount5"  : 1,
		"amount2"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
	]) );
	set( "build", 10001 );
	set( "owner", "tomorrow" );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room741",
		"south"     : "/open/clan/13_luck/room/room739.c",
	]) );
	set( "long", @LONG
這裡是tomorrow所排設的五行陣之一  火行陣 
眼前的火山正在冒著煙  隨時會爆炸  忽然轟的一響  火山爆發了
火熱的岩漿瞬間將四周吞沒  並且步步向你逼進
正當你回過神想逃的時候  卻發現身上的衣物已經著了火
這裡是tomorrow所排設的五行陣之一  火行陣 
眼前的火山正在冒著煙  隨時會爆炸  忽然轟的一響  火山爆發了
火熱的岩漿瞬間將四周吞沒  並且步步向你逼進
正當你回過神想逃的時候  卻發現身上的衣物已經著了
LONG);
	setup();
	replace_program(ROOM);
}
