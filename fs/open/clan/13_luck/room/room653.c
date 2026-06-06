inherit ROOM;
void create() {
	set( "short", "烈焰峽谷" );
	set( "owner", "evonne" );
	set( "build", 10020 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room651",
		"south"     : "/open/clan/13_luck/room/room649.c",
		"west"      : "/open/clan/13_luck/room/room652.c",
		"out"       : "/open/clan/13_luck/room/room648.c",
		"north"     : "/open/clan/13_luck/room/room650.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
你來到了烈燄峽谷，一處和外面的世界相連的地方，環顧四周皆為寸
草不長之地，由於終年經過峽谷內火燄的燒烤，至使峽谷地面龜裂不堪，尚
無完整之地。峽谷內的火都是由地面昇竄上來的，千百年始終沒有熄滅過，
從未有人知道為何會這樣，民間則戲傳是因上天不小心所遺留下來的火種所
造成的。走在峽谷內令人頻頻揮汗煩燥不堪，強風更助長了火勢，令人口乾
舌燥眼紅耳赤，一刻也不想待在這裡。

LONG);
	setup();
	replace_program(ROOM);
}
