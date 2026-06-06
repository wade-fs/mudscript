inherit ROOM;
void create() {
	set( "short", "刑天樓" );
	set( "owner", "roarii" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room596",
		"east"      : "/open/clan/13_luck/room/room598.c",
		"south"     : "/open/clan/13_luck/room/room600",
	]) );
	set( "long", @LONG
現在你來到了聖堂的主要樓閣－刑天樓，在這裡你隨處
所見都是一排又一排的槍架，槍架上有著許許多多各式各樣
的槍具。由此可見，聖堂不愧為當今武林天下第一槍術門派
。此外你抬頭一望，只見一副十分巨大的匾額高高掛在上頭
。上面刻著【聖龍霸槍－傲世名堂】看來！聖堂的確曾經是
武林中的一大門派。而站在這裡的中年男子肯定就是聖堂堂
主－狄無花。瞧他一副傲視群雄的感覺就知他不是好惹的！

LONG);
	setup();
	replace_program(ROOM);
}
