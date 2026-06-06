inherit ROOM;
void create() {
	set( "short", "gk eq-tooth" );
	set( "object", ([
		"amount9"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount8"  : 1,
	]) );
	set( "build", 10791 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room94",
	]) );
	set( "long", @LONG

使君從南來  五馬立踟躕

使君遣吏往  問此誰家姝

秦氏有好女  自名為羅敷

羅敷年幾何  二十尚不足

十五頗有餘  使君謝羅敷

寧可共載不  羅敷前致辭

使君一何愚  使君自有婦

羅夫自有夫  東方千餘騎

夫婿居上頭  何用識夫婿

白馬從驪駒  青絲繫馬尾

黃金絡馬頭  腰中鹿盧劍

可值千萬餘  十五府小史

二十朝大夫  三十侍中郎

四十專城居  為人潔白皙

鬑鬑頗有鬚  盈盈公府步

冉冉府中趨  坐中數千人

皆言夫婿殊


LONG);
	setup();
	replace_program(ROOM);
}
