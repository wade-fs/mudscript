inherit ROOM;
void create() {
	set( "short", "$BRED$時$BGRN$空$BYEL$倉$BBLU$庫$BMAG$之$NOR$$HIR$火靈焰扇$NOR$" );
	set( "owner", "car" );
	set( "object", ([
		"amount2"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount3"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"amount10" : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
	]) );
	set( "build", 10716 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room96",
	]) );
	set( "long", @LONG
火靈焰扇(fire fan),火飛笙所使用的寶扇,火光閃閃發亮的,令人無法直視,
火飛笙是段家的佼佼者,一陽指已經練到爐火純青,只要一交手馬上就會使出一
陽指封住你的功體,六脈神劍也會貫穿你的身體,火色靈光將襲擊你的氣血,而
打倒火飛笙就可以得到火靈焰扇,據說是開啟聚靈道的重要道具

LONG);
	setup();
	replace_program(ROOM);
}
