inherit ROOM;
void create() {
	set( "short", "郡王祠" );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room36.c",
		"south"     : "/open/clan/13_luck/room/room149",
	]) );
	set( "long", @LONG

    在前方，肅立了一位雕像，遠遠看去似乎閃耀著微微白光，你往
前一看，才晃然大悟，原來前面這個雕像傳奇人物，便是創立十三吉
祥傳說奇蹟的大功臣，也是這個幫派創始人~小南~他以一人之力，經
歷了種種考驗，重重危機，在虛幻和真實中建立了狂想世界，無人不
知，無人不曉的第一奇幫，難怪後人因此各以一甲子功力，創造了十
三奇景之一的寒冰像，紀念他，尊敬他。 

LONG);
	setup();
	replace_program(ROOM);
}
