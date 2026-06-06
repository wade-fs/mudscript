inherit ROOM;
void create() {
	set( "short", "聖堂大門" );
	set( "owner", "roarii" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room102",
		"enter"     : "/open/clan/13_luck/room/room601",
	]) );
	set( "long", @LONG
你眼前這一座大宅院正是震古鑠今的槍法世家－聖堂。
聖堂堂主－狄無花耗費了鉅資建立了這一座彷彿皇宮的大宅
院，為的就是重振聖堂十三年前的風光偉業！你身處在聖堂
大門，肯定對堂內十分的好奇。想看看裡面究竟是藏著何等
人物？但看見了一旁的兩名彪形大漢守衛，你不禁踟躕了。

LONG);
	setup();
	replace_program(ROOM);
}
