inherit ROOM;
void create() {
	set( "short", "人靈丹藥櫃" );
	set( "light_up", 1 );
	set( "build", 10046 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room293",
	]) );
	set( "long", @LONG
這裡是AMEI擺三種救命丹藥之中的人靈丹的地方，他的最大功效
就是能恢復所有的生命力，不過可惜的是他比起九轉蛇還丹和
生生造化丹的功效來的差，不過你拿不到前面這兩種救命仙丹
那人靈丹就是最強的，而且材料易取得假如你想要記得要跟
AMEI說O。。。。
LONG);
	setup();
	replace_program(ROOM);
}
