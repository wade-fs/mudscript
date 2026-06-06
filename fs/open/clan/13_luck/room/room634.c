inherit ROOM;
void create() {
	set( "short", "裝備間" );
	set( "owner", "blackdog" );
	set( "build", 10008 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room636",
	]) );
	set( "long", @LONG
在狂想呆的越久，就可以發現這裡的各式裝備多的嚇人，再加上這裡主
人捨不得丟棄的個性，各式裝備就愈存愈多了。在這裡你可以很看到初學者
就可以輕鬆取得的防具，也可以看到元老元家不需要所丟棄的高級裝備，可
惜的是因為主人的能力不足，還看不到需要戰功換取的裝備。

LONG);
	setup();
	replace_program(ROOM);
}
