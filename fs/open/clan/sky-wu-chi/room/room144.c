inherit ROOM;
void create() {
	set( "short", "$HIM$NISA的廁所$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "build", 10720 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room75",
		"south"     : "/open/clan/sky-wu-chi/room/room146.c",
	]) );
	set( "long", @LONG
你走在名為『玄武』走廊上你感覺到有一種不寒而慄的殺氣，比你剛剛
走的『白虎』走廊有過之而無不及，你感受到了空氣中有一股肅殺的氣息正
瀰蔓在四周，在一片的黑暗裡，你看不到四周有些什麼，只是感覺到有好幾
雙的眼睛正瞪著你看。猛然間你發現天花板壓了下來，你集忙的運了氣舉起
你的雙手向上那麼一撐，使用了千斤墜的功夫硬挺著，沒想到從四處跑出來
了四個護衛。那四隻護衛分別是叫『滅』『空』『武』『神』，都拿出了他
們的武器猛然的向你的身體四處猛然插下。

LONG);
	setup();
	replace_program(ROOM);
}
