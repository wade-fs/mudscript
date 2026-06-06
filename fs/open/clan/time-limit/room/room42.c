inherit ROOM;
void create() {
	set( "short", "$HIY$醫院$HIG$廂房$NOR$" );
	set( "owner", "goldblade" );
	set( "object", ([
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"amount8"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount10" : 1,
		"amount6"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount5"  : 1,
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
	]) );
	set( "build", 10006 );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room43",
	]) );
	set( "long", @LONG
不管任何人都會有生病受傷的時候,尤其學習魔法更是容易受傷,
因此學校裡設有醫院來解決生病受傷的問題,護理長'龐內夫人'
是位醫術高超的醫者,任何疑難雜症都難不倒她,醫院裡有三張病床,
櫃子上擺滿藥草和正在冒煙的魔藥,有了這樣的醫院和醫者就可以安心學習魔法了

LONG);
	setup();
	replace_program(ROOM);
}
