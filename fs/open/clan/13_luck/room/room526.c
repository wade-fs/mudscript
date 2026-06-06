inherit ROOM;
void create() {
	set( "short", "前堂" );
	set( "build", 10145 );
	set( "owner", "fireer" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room525.c",
		"north"     : "/open/clan/13_luck/room/room513",
		"east"      : "/open/clan/13_luck/room/room527.c",
	]) );
	set( "long", @LONG
這裡便是易水樓的前堂了，雖然在裝飾上不可能像宮殿般的華麗，
不過也稱得上是奢華了。一想到自己即將走進在武林如霧縹緲般傳說的
神秘地帶，心裡就不由得的打了個冷顫。有個神態瀟灑的公子站在前方
，等著人們的到來，好迎接下一個任務。然而在往前便是前廳了。
LONG);
	setup();
	replace_program(ROOM);
}
