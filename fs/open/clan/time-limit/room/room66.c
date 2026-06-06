inherit ROOM;
void create() {
	set( "short", "$HIR$禁忌$HIG$森林2$NOR$" );
	set( "owner", "firefan" );
	set( "object", ([
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount8"  : 1,
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount10" : 1,
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount5"  : 1,
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount6"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"amount4"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount9"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount3"  : 1,
	]) );
	set( "build", 11530 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room67",
	]) );
	set( "long", @LONG
前方的樹叢裡有著生物在動,忽然間一隻獨角獸從樹叢走出,你不禁感到震驚,
這世上竟有如此美的生物,全身銀色毛髮閃閃發亮,頭頂的角長又尖,
雙眼炯炯有神,充滿魔法氣息的生物,獨角獸的毛可以做為魔杖的材料,
獨角獸的血更可以延續生命,但是殺害獨角獸將會受到詛咒,失去所有的力量

LONG);
	setup();
	replace_program(ROOM);
}
