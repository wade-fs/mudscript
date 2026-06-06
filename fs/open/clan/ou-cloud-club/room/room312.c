inherit ROOM;
void create() {
	set( "short", "$HIC$天空之城$NOR$--$HIY$丹$NOR$" );
	set( "object", ([
		"file8"    : "/obj/gift/xiandan",
		"file6"    : "/obj/gift/xiandan",
		"amount1"  : 1,
		"amount7"  : 1,
		"amount5"  : 1,
		"amount2"  : 1,
		"file2"    : "/obj/gift/xiandan",
		"file5"    : "/obj/gift/xiandan",
		"file7"    : "/obj/gift/xiandan",
		"file1"    : "/obj/gift/xiandan",
		"file3"    : "/obj/gift/xiandan",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"file4"    : "/obj/gift/xiandan",
		"amount6"  : 1,
	]) );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room308",
	]) );
	set( "owner", "del" );
	set( "build", 10064 );
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
