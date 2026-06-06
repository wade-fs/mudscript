inherit ROOM;
void create() {
	set( "short", "$HIG$不$HIM$夜$HIC$天$NOR$" );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room198",
	]) );
	set( "long", @LONG
不夜天地如其名,四周掛滿了燈籠,將黑夜照亮如白晝,不夜天裡的鳥語花香,蝴蝶翩翩飛
舞,庭園的花草爭奇鬥豔,好一幅人間仙境,涼亭上擺了一座古箏,江南第一才女風采玲正
在彈奏一首紅塵淚,聽的你如癡如醉,風采玲身後站著兩位大漢,正是刀獸與劍禽,一旁的
桌子上擺著棋盤與文房四寶,等著素還真到來時能與他切搓研究

LONG);
	setup();
	replace_program(ROOM);
}
