inherit ROOM;
void create() {
	set( "short", "$HIY$香蕉週刊$HIB$有靶兒$HIW$廁所$NOR$" );
	set( "object", ([
		"amount3"  : 1,
		"file2"    : "/open/magic-manor/obj/evil-kill-claw",
		"file3"    : "/open/magic-manor/obj/evil-kill-claw",
		"file5"    : "/open/main/obj/unarmed-b",
		"amount5"  : 1,
		"file1"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount1"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount2"  : 1,
	]) );
	set( "owner", "blur" );
	set( "build", 10296 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room96.c",
		"south"     : "/open/clan/hell/room/room34.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
這裡就是香蕉週刊的男廁所了...
有位阿婆整天在這兒拖地...
也不知道真拖地還是假拖地....
只見阿婆盯著來來往往的便客看...
像是一付要嚐盡天下香腸的樣子..
真是 價 恐 佈 !!
這時老大阿飛進來撇尿...
阿婆如同往常邊拖地邊偷瞄...
只見阿婆臉色大變.....旋急就奪門而出...大叫 
天阿!! 大蟒蛇!!! 
阿飛呵呵兩聲...顫抖了兩下..就把巨蟒收了起來..走了出去..
LONG);
	setup();
	replace_program(ROOM);
}
