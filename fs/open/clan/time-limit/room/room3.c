inherit ROOM;
void create() {
	set( "short", "$HIM$玄武$HIR$時$HIG$空$NOR$ " );
	set( "build", 10328 );
	set( "exits", ([
		"pass"      : "/open/clan/time-limit/room/room9",
		"south"     : "/open/clan/time-limit/room/hall.c",
	]) );
	set( "long", @LONG
這裡是時空秘境中的玄武時空,由巨大暗黑的玄武岩所建造的一扇門
佇立在眼前,四周沒有任何的東西,幽暗的環境散發著魔法的氣息,
忽然玄武大門慢慢打開了,從門裡射出淡淡的光線,並且搖擺不定,
好像是被風吹動的蠟燭之光,但是你並沒有感受到風,
難道是在另一個時空,這已挑動自己的好奇心了

LONG);
	setup();
	replace_program(ROOM);
}
