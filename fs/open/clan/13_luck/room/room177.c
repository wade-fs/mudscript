inherit ROOM;
void create() {
	set( "short", "魔森林" );
	set( "object", ([
		"amount2"  : 1,
		"file2"    : "/open/firedancer/npc/eq/r_pants",
		"file4"    : "/open/firedancer/npc/eq/r_boots",
		"file1"    : "/open/firedancer/npc/eq/r_hands",
		"amount3"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/firedancer/npc/eq/r_finger",
	]) );
	set( "build", 10485 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room179",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    一進來這邊發現眼前是片一望無際的森林，如果仔細觀察的話會
發現森林中有許多從來沒見過的雕像，就在你想要靠近雕像的同時，
突然從雕像裡面衝出一群面目猙獰的怒馬瘋鬼，瘋狂地向你逼近，此
時你已經後悔觸動機關，但是一切都太遲了....你的眼前一黑，接著
什麼也不知道了。

LONG);
	setup();
	replace_program(ROOM);
}
