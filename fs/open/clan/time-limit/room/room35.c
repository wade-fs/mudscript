inherit ROOM;
void create() {
	set( "short", "$YEL$地底$CYN$隧道$NOR$" );
	set( "exits", ([
		"out"       : "/open/clan/time-limit/room/room36",
		"snake"     : "/open/clan/time-limit/room/room34",
	]) );
	set( "long", @LONG
通過長長的水管通道,來到一個幽暗的地底隧道,地上堆滿動物的骨頭,
一股無形的恐懼湧上心頭,再往前走,前方有個巨大的不明物體,
仔細一看,原來是蛇蛻皮後所留下的皮,而且這皮至少有30公尺長,
蛻完皮之後的蛇會有多長呢,你不禁兩腳發軟,繼續往前走到底,
前方已無通道,只有一面石牆,牆上刻著蛇的雕像

LONG);
	setup();
	replace_program(ROOM);
}
