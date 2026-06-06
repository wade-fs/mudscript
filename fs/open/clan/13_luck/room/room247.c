inherit ROOM;
void create() {
	set( "short", "『桃花林』 " );
	set( "owner", "mill" );
	set( "object", ([
		"file7"    : "/obj/gift/bingtang",
		"file8"    : "/obj/gift/unknowdan",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/tendo/obj/chaosbelt",
		"file6"    : "/obj/gift/shenliwan",
		"amount8"  : 1,
		"amount3"  : 9,
		"amount1"  : 1,
		"file9"    : "/obj/gift/bingtang",
		"file10"   : "/open/mogi/dragon/obj/power",
		"file4"    : "/obj/gift/bingtang",
		"file2"    : "/obj/gift/hobowdan",
		"file1"    : "/obj/gift/lingzhi",
		"amount9"  : 1,
		"file3"    : "/open/mogi/castle/obj/blood-water",
	]) );
	set( "build", 10008 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room106",
		"south"     : "/open/clan/13_luck/room/room261.c",
	]) );
	set( "long", @LONG
四周長滿了濃密的桃花，感覺上好像很漂亮，可是一面白茫茫的桃花林
，不知道要往哪裡去，只有依稀聽見遠方傳來一些聲音，似乎有人的聲音。
只是放眼望過去，整片都是桃花，讓你無所適從，四周緊張的空氣讓你的緊
覺心提高了許多，一步一步的往桃花林的深處走去。
LONG);
	setup();
	replace_program(ROOM);
}
