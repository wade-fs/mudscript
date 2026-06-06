inherit ROOM;
void create() {
	set( "short", "ddddd2" );
	set( "object", ([
		"file2"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount4"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/mon/obj/ghost-cloak",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10117 );
	set( "light_up", 1 );
	set( "long", @LONG
你走進一片荒廢的遺跡. 雕刻精緻且造型高古, 本應是矗立
於兩旁的石柱, 斑駁散亂的傾頹地面, 隱約可見的是攀附其上的
苔蘚. 作為道路的石版, 早已碎裂不堪. 儘管如此, 仍有其別具
特色的紋理. 潮濕的霧氣, 憑添了一種迷濛的氣氛, 罩上了一層
神秘的面紗. 這只有風聲, 水滴聲, 以及你自己的腳步聲. 但你
卻不能肯定, 在什麼時候, 在什麼地方, 會有什麼東西出現在你
背後.
LONG);
	setup();
	replace_program(ROOM);
}
