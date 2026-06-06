inherit ROOM;
void create() {
	set( "short", "沙灘" );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room141",
	]) );
	set( "long", @LONG
沙灘沿著岸邊不斷的連綿下去,看來島的這一頭全屬於沙岸的類型,北邊依然
是密密麻麻的防風林,高大的防風林樹木讓你無法看到島上的任何情況,而且也沒
辦法貿然深入,一個不好迷失在此就更糟糕了,海風不斷地在耳邊呼嘯,看來應該
盡快的找到可以安身的地方了.

LONG);
	setup();
	replace_program(ROOM);
}
