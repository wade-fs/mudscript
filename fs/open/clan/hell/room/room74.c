inherit ROOM;
void create() {
	set( "short", "$HIY$黃龍$NOR$區" );
	set( "object", ([
		"amount3"  : 76,
		"file2"    : "/open/fire-hole/obj/y-pill",
		"file3"    : "/open/fire-hole/obj/y-pill",
		"file1"    : "/open/fire-hole/obj/y-pill",
		"amount1"  : 100,
		"amount2"  : 100,
	]) );
	set( "owner", "blur" );
	set( "build", 11195 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room27",
	]) );
	set( "long", @LONG

嗯! 黃龍..顧名思義..就是黃顏色的龍...
黃龍精元的功用就是增加劍士的能力...
但是小弟沒玩過劍士...實在不知道怎麼寫...
那來談談我的吞雲吐霧心得好了...
(萬寶路)<--第一種接觸的菸,口感不錯...蠻純的,但有時會絕得太濃
(大衛杜夫)<--不錯的德國菸,有其獨特的味道,但小弟不太喜歡...
(Boss)<--也是德國菸,感覺比大衛淡一點,還蠻順口...
(YSL)<--難抽的英國菸,良心建議..別浪費錢..


                          (^^ ..下文請閱BBB)

LONG);
	setup();
	replace_program(ROOM);
}
