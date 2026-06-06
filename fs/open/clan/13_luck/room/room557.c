inherit ROOM;
void create() {
	set( "short", "你會選擇什麼呢?(5)" );
	set( "owner", "dfyw" );
	set( "object", ([
		"amount3"  : 1,
		"file9"    : "/obj/gift/shenliwan",
		"amount9"  : 1,
		"file7"    : "/obj/gift/unknowdan",
		"amount7"  : 1,
		"file3"    : "/obj/gift/unknowdan",
	]) );
	set( "build", 10043 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room560",
	]) );
	set( "long", @LONG
貪心想要兩者得兼，結果最是傷人；
狠心拋下一邊，卻是午夜夢迴，總難成眠。
其實無心選擇，但卻必得承受事發的後果。
我想，這就是人生吧！雖然有點無奈，
有點倀然，但是暸解了，也就更能釋懷了，
然後，安慰自己並且鼓勵他人，還是要好好快樂的活。
這也是人生。
LONG);
	setup();
	replace_program(ROOM);
}
