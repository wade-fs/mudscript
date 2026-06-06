inherit ROOM;
void create() {
	set( "short", "紅塵閣三樓" );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room115",
	]) );
	set( "long", @LONG

    凌空渡虛，御氣而行，漫步走至紅塵居三樓。回想自己的過去，
從一個武學門外漢，一路苦練至今武學修為終於達到頂峰，為求武功
更為精進，故來到武林高手群眾的此地，盼能受到武林前輩的指導，
以再突破自身的極限。

LONG);
	setup();
	replace_program(ROOM);
}
