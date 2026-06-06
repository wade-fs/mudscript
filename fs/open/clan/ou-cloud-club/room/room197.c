inherit ROOM;
void create() {
	set( "short", "$HIY$地震帶$NOR$" );
	set( "object", ([
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount3"  : 1,
		"amount7"  : 1,
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount10" : 1,
		"amount6"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount9"  : 1,
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 1,
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount8"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"amount4"  : 1,
	]) );
	set( "build", 10559 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room18.c",
		"north"     : "/open/clan/ou-cloud-club/room/room473",
		"east"      : "/open/clan/ou-cloud-club/room/room200.c",
		"west"      : "/open/clan/ou-cloud-club/room/room198.c",
	]) );
	set( "long", @LONG
巨大的身形矗立在遠方，遠古的力量之神『泰坦』正守護著
這裡，寬闊的背影讓人心中湧現一股安定的感覺，你不禁想著要
盡快變強能夠去守護別人，隨手抓起一把泥土灑向空中，霎時間
變成無數的光點落在你的身上，一股莫名的力量在體內湧現。

左邊是小敏(mming)練功的房間，右邊則歐胡(Julio)的青山房．

LONG);
	setup();
	replace_program(ROOM);
}
