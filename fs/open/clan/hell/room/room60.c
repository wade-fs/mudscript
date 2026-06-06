inherit ROOM;
void create() {
	set( "short", "魔之右手" );
	set( "object", ([
		"file1"    : "/daemon/class/fighter/figring",
		"amount1"  : 1,
	]) );
	set( "build", 13364 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room24",
		"west"      : "/open/clan/hell/room/room62.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
    
        一進入這裡，立刻被一股嗜殺的氣勁所包圍，除此之外還有一股凶暴
        殘忍的感覺出現，而目光馬上被眼前的一座雕像(statue)所誘惑，只
        見雕像身著血紅怪異的邪惡裝備，慢慢眼神迷失在瘋狂的強大漩渦當
        中，突然四周暴戾之氣被你吸收，讓你擁有遇神殺神的終極力量。


LONG);
	setup();
	replace_program(ROOM);
}
