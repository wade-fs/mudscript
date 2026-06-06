inherit ROOM;
void create() {
	set( "short", "鎖龍塔休息室" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room210",
		"north"     : "/open/clan/13_luck/room/room208",
	]) );
	set( "long", @LONG

　　一路上歷經萬難，總算找到這一小小的避風港。環顧四周地處隱
密，應該不虞會被龍群發現這藏身之處，總算可以安心的休養生息一
下了！！看來前途奸險，不如趁此良機好好休息一下，待會才能繼續
冒險的旅程，拯救昌生於一己！！

LONG);
	setup();
	replace_program(ROOM);
}
