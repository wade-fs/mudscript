inherit ROOM;
void create() {
	set( "short", "桃花林" );
	set( "owner", "evonne" );
	set( "object", ([
		"file8"    : "/open/mogi/castle/obj/seven1-dark-head",
		"file6"    : "/open/mogi/castle/obj/seven3-dark-head",
		"file1"    : "/open/mogi/castle/obj/white-ghost-head",
		"file10"   : "/open/mogi/castle/obj/black-ghost-head",
		"amount2"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/mogi/castle/obj/seven4-dark-head",
		"file3"    : "/open/mogi/castle/obj/seven6-dark-head",
		"amount4"  : 1,
		"file2"    : "/open/mogi/castle/obj/seven5-dark-head",
		"amount5"  : 1,
		"file9"    : "/open/mogi/castle/obj/white-ghost-head",
		"file4"    : "/open/mogi/castle/obj/seven7-dark-head",
		"amount3"  : 1,
		"file7"    : "/open/mogi/castle/obj/seven2-dark-head",
		"amount9"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10313 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room493",
	]) );
	set( "long", @LONG

    四周長滿了濃密的桃花，感覺上好像很漂亮，可是一面白茫茫的
桃花林，不知道要往哪裡去，只有依稀聽見遠方傳來一些聲音，似乎
有人的聲音。只是放眼望過去，整片都是桃花，讓你無所適從。四周
緊張的空氣讓你的緊覺心提高了許多。

LONG);
	setup();
	replace_program(ROOM);
}
