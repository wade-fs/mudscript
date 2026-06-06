inherit ROOM;
void create() {
	set( "short", "$BRED$時$BGRN$空$BYEL$倉$BBLU$庫$BMAG$之$NOR$$HIG$綠色靈劍$NOR$" );
	set( "owner", "car" );
	set( "object", ([
		"amount2"  : 1,
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount10" : 1,
	]) );
	set( "build", 10799 );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room96",
	]) );
	set( "long", @LONG
綠色靈劍(wood sword),木燃落所使用的寶劍,綠光閃閃奪目,令人無法直視,
木燃落是仙劍的高手,並已達到劍聖的境界,會使用破體連陽七訣斬,可能會讓
你因劍芒而炫目,無法使用特攻,綠色靈光會治療傷口並補血,讓木燃落可以更
持久地戰鬥,而打倒木燃落就可以得到綠色靈劍,據說是開啟聚靈道的重要道具

LONG);
	setup();
	replace_program(ROOM);
}
