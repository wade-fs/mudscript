inherit ROOM;
void create() {
	set( "short", "$BRED$雲路$BGRN$天宮$NOR$" );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room198",
	]) );
	set( "long", @LONG
四周雲霧飄渺,路徑也不清楚,只能緩步前進,前方有個黑色的巨大建築物,應該就是雲路
天宮了,經過一段路程,終於來到門口,黑色的大門給人沉重的感覺,但是雲路天宮的少宮
主蕭竹盈是少有的美人,並且還是刀狂劍痴葉小釵的妻子,雲路天宮宮主流星君培養十三
流星以壯大勢力,卻不知十三流星中有人心懷不軌

LONG);
	setup();
	replace_program(ROOM);
}
