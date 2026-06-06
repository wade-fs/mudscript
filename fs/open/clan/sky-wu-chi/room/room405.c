inherit ROOM;
void create() {
	set( "short", "朱雀上將軍府" );
	set( "owner", "poiiiiop" );
	set( "build", 10023 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room407",
	]) );
	set( "long", @LONG
    有心 無心 心在人間 多情 薄情 情繫江湖 
莫道世情怨不平 召意心築不染塵 奴夢濺淚痕未乾 還念真情巢涯生
莫道吾心深似海 召蜂引蝶非吾願 奴家真身難分辨 且待霹靂照青天

         東瀛浪子逐海潮，君子心定有情巢。
         護保家國兵燹事，背負龍怨藏文詔。
         情絲無語沈何處，流金歲月歎夢瑤。
         風塵血淚江湖路，清菊小苑慰寂寥。

衝鋒卸陣、敖勇善戰，被後世稱為『火之鳳凰』的朱雀上將軍 - 莫召奴
LONG);
	setup();
	replace_program(ROOM);
}
