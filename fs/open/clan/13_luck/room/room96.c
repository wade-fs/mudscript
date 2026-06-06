inherit ROOM;
void create() {
	set( "short", "紅塵閣" );
	set( "build", 750 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room40.c",
		"醉臥亭"    : "/open/clan/13_luck/room/room160",
		"up"        : "/open/clan/13_luck/room/room115.c",
	]) );
	set( "long", @LONG

$HIC$桌上擺著一杯茶，喝了一口陣陣清香味散滿了四周，這種感覺真是舒
服，飄落的花雪在空中慢慢的落下，寒風瀟瀟更增加了幾分冷意，霜
雪蓋滿了$HIR$「紅塵居」$HIC$的屋頂，十三吉祥最高殊榮盡皆於此，踏進門口
往前一看，你不禁駭然一聲，原來牆上高掛了二行字正是︰$NOR$

       $HIW$～～天下群雄何其多～～$NOR$
                               $HIW$～～$HIY$十三吉祥$HIW$傲群雄～～$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
