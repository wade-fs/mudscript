inherit ROOM;
void create() {
	set( "short", "為我好" );
	set( "owner", "yaoblade" );
	set( "object", ([
		"file3"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount1"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount2"  : 1,
	]) );
	set( "build", 10063 );
	set( "exits", ([
		"south"     : "/open/clan/nine-sky-dragon/room/room25",
	]) );
	set( "long", @LONG
才知道　你臉上的微笑　不是幸福代表　是種不自在的禮貌 
才知道　感情已經動搖　我一直被誤導　是你還不願意揭曉 
太多小煩惱　怪我們不懂得拋　太多的問號　答案也都不必找 
只換來疲勞　忘了要一起變老
為何要無話可說　才懂沉默比爭吵難熬 
為何會在恨消失後 愛還是挽回不了
為何要在疼愛我的時候　才對我說離開我　都是為我好 
才知道　感情已經動搖　我一直被誤導　是你還不願意揭曉 
太多小煩惱　怪我們不懂得拋　太多的問號　答案也都不必找 
只換來疲勞　忘了要一起變老 
為何要無話可說　才懂沉默比爭吵難熬 
為何會在恨消失後　愛還是挽回不了 
為何要在疼愛我的時候　才對我說離開我　都是為我好

LONG);
	setup();
	replace_program(ROOM);
}
