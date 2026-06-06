inherit ROOM;
void create() {
	set( "short", "血痕居-翠煙吟" );
	set( "owner", "holeman" );
	set( "build", 11753 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room518",
	]) );
	set( "long", @LONG

    世上男兒多寡信，人間薄命總紅顏。
    佳人離世入幽谷，從此不問世間緣。
    山中雖無日與月，但得清靜無塵煩。
    冰凍千里風捲雪，谷中霧漫浮雲散。
    碧海潮生動山河，牧野流星飾長天。
    倩影冰心獨自賞，雨打梨花淚光寒。
    冰淚全由冰心結，冰心雪骨誰堪憐？
    踏雪無痕絕蹤跡，寒冰護體斷情緣。
    都道此地為仙境，欲尋多時無人還。
    只因未有癡男子，怎叫仙女肯下凡？



LONG);
	setup();
	replace_program(ROOM);
}
