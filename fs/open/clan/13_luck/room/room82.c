inherit ROOM;
void create() {
	set( "short", "小劉的狗屋" );
	set( "owner", "djlh" );
	set( "object", ([
		"file9"    : "/open/gsword/obj/spsword-4",
		"file6"    : "/open/quests/snake/npc/obj/snake-key-2",
		"amount9"  : 1,
		"file7"    : "/open/killer/obj/dagger",
		"amount1"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file1"    : "/daemon/class/fighter/figring",
	]) );
	set( "light_up", 1 );
	set( "build", 10074 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room55",
	]) );
	set( "long", @LONG
剛進來就有一個衝動想溜Q.Q
懷疑是不是跑錯房間,也許這就是傳說中的'鬼不理狗屋'
但是正這麼想時卻看到旁邊辛苦在畫戰版的小劉@@~才想到這真的是真正的鬼不理狗屋
四周有一堆櫃子,仔細一看,蠟筆啦.連筆削也沒掃,天ㄚ~連渾天水晶也幹過來放~真是比賤狗還還劍還來的濫
真是有夠OOXX的倫~也許活到現在也快成化石了
LONG);
	setup();
	replace_program(ROOM);
}
