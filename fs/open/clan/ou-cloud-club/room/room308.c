inherit ROOM;
void create() {
	set( "short", "$HIC$天空之城$NOR$--$HIR$丹$NOR$" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room312",
		"east"      : "/open/clan/ou-cloud-club/room/room210.c",
	]) );
	set( "owner", "del" );
	set( "object", ([
		"amount1"  : 1,
		"file10"   : "/obj/gift/unknowdan",
		"amount4"  : 1,
		"file7"    : "/obj/gift/unknowdan",
		"file2"    : "/obj/gift/unknowdan",
		"amount7"  : 1,
		"file1"    : "/obj/gift/unknowdan",
		"amount5"  : 1,
		"file4"    : "/obj/gift/xiandan",
		"amount10" : 1,
		"file5"    : "/obj/gift/unknowdan",
		"amount3"  : 1,
		"file3"    : "/obj/gift/unknowdan",
		"amount2"  : 1,
	]) );
	set( "build", 10088 );
	set( "light_up", 1 );
	set( "long", @LONG
冰冷的湖水讓你的手腳有點不聽使喚，但求生的原始本
能卻讓你不自覺的划動手腳前進，慢慢的也能適應而在其中
悠遊，環顧四下，除了陽光透過水面的些微光線之外，湖底
盡是一片不可測的慘綠，偶而一小群游魚從你身旁游過，卻
不因為你的突然出現而有所驚嚇，算了，還是快找出口吧。
ˉ
LONG);
	setup();
	replace_program(ROOM);
}
