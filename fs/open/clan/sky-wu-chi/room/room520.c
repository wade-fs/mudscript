inherit ROOM;
void create() {
	set( "short", "血痕居-白鶴拳" );
	set( "owner", "holeman" );
	set( "build", 10133 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room526",
		"east"      : "/open/clan/sky-wu-chi/room/room519.c",
		"north"     : "/open/clan/sky-wu-chi/room/room524.c",
	]) );
	set( "long", @LONG

學就金剛之勢  練成羅漢之姿  青鋒橫可斷石  紫電渺而難追

力隨身動處得  智與道進時隨  手開如抱日月  腳動卻轉須彌

八法縱橫離對  步罡箭竄盤絲  龍神鶴形猿步  蛇身進用虎威

不動太虛在眼  動時山嶽崩頹  柔時柳絮無骨  動時剛勝金精

佛掌指開彌勒  因時按穴尋思  棉裡金針微密  於無所往而施

龍象自在爾體  雲何不何施為  王法自然是道  定慧自有餘思



LONG);
	setup();
	replace_program(ROOM);
}
