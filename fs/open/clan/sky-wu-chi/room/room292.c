inherit ROOM;
void create() {
	set( "short", "地靈丹藥櫃" );
	set( "owner", "amei" );
	set( "object", ([
		"amount2"  : 1,
		"amount1"  : 2,
		"file2"    : "/open/fire-hole/obj/g-pill",
		"file1"    : "/open/fire-hole/obj/r-pill",
	]) );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "build", 10089 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room293",
	]) );
	set( "long", @LONG
這裡是AMEI擺三種救命丹藥之中的地靈丹的地方，他的最大功效
就是能解百毒，不過可惜的是他卻無法解除七魔將和黑白雙煞的
入滅之毒，真是有點可惜。。。這裡擺滿了丹藥看起來價值不菲。。
你假如想要拿一些記得要跟AMEI說一下O 。。。。
LONG);
	setup();
	replace_program(ROOM);
}
