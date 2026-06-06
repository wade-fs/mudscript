inherit ROOM;
void create() {
	set( "short", "$HIM$【$HIY$豬神界$HIM$】$NOR$" );
	set( "build", 10386 );
	set( "exits", ([
		"up"        : "/open/clan/hell/room/room8.c",
		"west"      : "/open/clan/hell/room/room46",
		"down"      : "/open/clan/hell/room/room5.c",
		"east"      : "/open/clan/hell/room/room18.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

$WHT$這裡是$HIG$^(OO)^$WHT$的地盤，到處瀰漫著怪異的味道............
掌管者是$HIB$kalin,$WHT$他正專心的看著$HIR$小澤圓$WHT$的告別座，嘴角還不時流出一絲絲的豬涎。
看來真是讓人嘔吐到最高點!!!!!突然他轉過頭來對你奸笑幾聲，你不禁嚇了一大跳!!!
心裡直想著 : 還是快點離開這個淫窟地方好了，不然哪一天我的$HIM$菊花$WHT$又要開了.. :P$NOR$


LONG);
	setup();
	replace_program(ROOM);
}
