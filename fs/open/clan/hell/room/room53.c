inherit ROOM;
void create() {
	set( "short", "$HIW$黑輪臥房 - $HIC$主室$NOR$" );
	set( "owner", "radio" );
	set( "build", 10073 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room40",
		"north"     : "/open/clan/hell/room/room40",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
這裡就是黑輪臥室的主房了，眼前這位便是傳說
說中的劍魔‧  他正在閉目養神‧即使如此身上還是
流出驚人的殺戾之氣，你不由的退後了幾步，深怕驚
醒了這位  劍 中 之 魔 ‧ 黑 輪

(殺意狂暴)劍魔「嗜血劍」黑輪(Jinkazama)

LONG);
	setup();
	replace_program(ROOM);
}
