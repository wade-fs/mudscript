// Room : /open/clan/ou-cloud-club/room/room96.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
	set( "short", "$HIM$魔女ソ研究室$NOR$" );
	set( "owner", "jenova" );
	set( "object", ([
		"file10"   : "/open/capital/obj/blade2",
		"amount7"  : 1,
		"file6"    : "/open/ping/questsfan/obj/diamond_hands",
		"amount5"  : 1,
		"amount8"  : 2850,
		"file1"    : "/open/ping/questsfan/obj/diamond_hairpin",
		"file2"    : "/open/ping/questsfan/obj/diamond_belt",
		"amount3"  : 1,
		"file8"    : "/obj/poison/five_poison",
		"file5"    : "/open/ping/questsfan/obj/diamond_armor",
		"file4"    : "/open/ping/questsfan/obj/diamond_legging",
		"amount2"  : 1,
		"amount9"  : 1,
		"file7"    : "/open/ping/questsfan/obj/diamond_cloak",
		"file3"    : "/open/ping/questsfan/obj/diamond_boots",
		"amount10" : 1,
		"file9"    : "/open/capital/obj/gold_pill",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10200 );
	set( "exits", ([
		"add"       : "/open/clan/ou-cloud-club/room/room356",
		"up"        : "/open/clan/ou-cloud-club/room/room87.c",
	]) );
	set( "long", @LONG

    老舊的櫥櫃,佈滿了厚厚的一層灰塵,櫃子裡放的,是一罐罐來歷不明
的藥水,據娃哈哈本人表示,這些藥水都是她一生努力研究出來的結晶,的
確,當你看到身後那座擺滿了古今中外各種醫學書籍的大書架時,就不難想
像娃哈哈功力之精深了,其實這裡還有一個鮮為人知的秘密,據說這裡是某
亞洲大國的最大礦泉水出產區,看來娃哈哈真的不是一位簡單的人物.

LONG);
	set( "no_clean_up", 0 );
	setup();

	}
