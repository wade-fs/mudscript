inherit ROOM;
void create() {
	set( "short", "$HIW$當舖$HIR$ソ$HIC$東廂房$NOR$" );
	set( "owner", "yuki" );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room539",
		"east"      : "/open/clan/sky-wu-chi/room/room423",
	]) );
	set( "build", 10059 );
	set( "light_up", 1 );
	set( "long", @LONG
    斗室裡青煙繚繞，置著一張橫几、兩個蒲團，一柄烏鞘金吞的古
劍供在几頂，粉壁上懸著一幅中堂，筆力遒勁，寫的是唐代詩人賈島
的一首《俠客》：「十年磨一劍，霜刃未曾試。今日把示君，誰有不
平事？」廳側吊著一簾青幔，幔後透出些許燈光周圍隱隱顯露出一股
俠客之氣!! 映入眼簾令你驚訝的是堆落滿地的武功書籍,顯示此處的
主人亦是武林俠客之一!

LONG);
	setup();
	replace_program(ROOM);
}
