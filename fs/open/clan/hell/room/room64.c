inherit ROOM;
void create() {
	set( "short", "$HIY$$HBRED$護衛戒指$NOR$存放區" );
	set( "owner", "blur" );
	set( "object", ([
		"amount3"  : 1,
		"file3"    : "/open/capital/guard/gring",
		"file1"    : "/open/capital/guard/gring",
		"amount5"  : 1,
		"file6"    : "/open/capital/guard/gring",
		"amount2"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/capital/guard/gring",
		"file2"    : "/open/capital/guard/gring",
		"amount6"  : 1,
		"file5"    : "/open/capital/guard/gring",
		"amount1"  : 1,
	]) );
	set( "build", 10831 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room39",
	]) );
	set( "long", @LONG
護衛戒指算是戒指裡頭較難取得的裝備了,然而由於他會分享經驗值得這個
缺點,再加上地府的幫眾大部分都有深厚的功力,平常是很少在用它的,不過這個
戒指再對大型敵人戰鬥的時候,仍然有一定的效果,小敏幫主特地將幫裡的護衛戒
指集中到這裡給大家取用,希望大家用畢可以歸還

LONG);
	setup();
	replace_program(ROOM);
}
