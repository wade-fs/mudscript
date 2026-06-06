inherit ROOM;
void create() {
	set( "short", "天杖堂比鬥場" );
	set( "build", 10041 );
	set( "owner", "fireer" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room504",
	]) );
	set( "long", @LONG
走來這裡，感覺到一股魄力直逼四周，靜謐的氣氛散發全場。只有
屈指可數的弟子可以在此比鬥場練武比試，以增加實戰經驗，好可以隨
時支援任務。雖然他們的衣著十分不顯眼，但全身上下卻散發一股源源
不絕的熱力以及濃厚的殺氣，由此看來，就知道絕非等閒之輩。
LONG);
	setup();
	replace_program(ROOM);
}
