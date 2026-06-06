// Room : /open/clan/sky-wu-chi/room/room78.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
	set( "short", "$HIR$NISA的廚房$NOR$" );
	set( "build", 12160 );
	set( "long", @LONG
你來到了一個叫『梅花雪影居』地方，這個地方似乎比外面的七色結界更具
吸引力你看到了一個猶如萬斤重的黃銅鐵門，你於是乎不敢掉以輕心的隨意就想
把門打開你運足了氣勁，大喝一聲『萬馬奔騰』結果令你驚訝的事發生了。鐵門
紋風不動。只有下你的掌印，仔細著一看門上的傷痕有許多。就好像在述說著許
多的人也來過此地一探。當你在思考之時你卻看到門一點點的被打開了。走出來
的竟是一位女子原來這位女子就是裡頭的夫人『青兒』。
她正熱情的招待你進去這謎樣般的居所,你也正好想要進去一窺究竟,看看裡面
到底是有些什麼樣讓你能夠驚訝連連的東西

LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"south"     : "/open/clan/sky-wu-chi/room/room409",
		"north"     : "/open/clan/sky-wu-chi/room/room146.c",
]) );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "clan_room", "天道無極" );
	setup();

	}
