inherit ROOM;
void create() {
	set( "short", "$BRED$古$BMAG$靈$BCYN$閣$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount5"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount7"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-pants",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount2"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount6"  : 1,
		"amount10" : 1,
	]) );
	set( "owner", "car" );
	set( "build", 10553 );
	set( "exits", ([
		"pass"      : "/open/clan/time-limit/room/room43",
		"east"      : "/open/clan/time-limit/room/room51.c",
	]) );
	set( "long", @LONG
古靈閣由妖精所開設,幾個妖精奮筆疾書記錄,幾個妖精抱著寶石在秤重,
一位魔法部的人和妖精的主管談論物價指數的問題,
許多巫師拿著申請表要領款,也有巫師捧著錢要存進去,
感覺和一般世界的銀行沒什麼不同,不過一般世界的銀行會被搶,
卻沒有巫師敢搶古靈閣,因為妖精是一般巫師惹不起的角色,
何況金錢都存放在地底下,還有龍看守著,就算搶到錢也不見得找到路出來
可能還沒出來就餓死了,一旁可用呼嚕粉和霍格華茲的分行相通


LONG);
	setup();
	replace_program(ROOM);
}
