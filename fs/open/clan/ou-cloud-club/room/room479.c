inherit ROOM;
void create() {
	set( "short", "$HIC$傲$HIW$雲$HIY$閤$HIG$四樓$HIM$中庭$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"amount7"  : 1,
		"amount9"  : 1,
		"amount6"  : 1,
		"file5"    : "/open/gsword/obj1/bpball",
		"amount1"  : 1,
		"file3"    : "/open/gsword/obj1/bpball",
		"amount10" : 1,
		"amount8"  : 1,
		"file7"    : "/open/gsword/obj1/bpball",
		"file10"   : "/open/gsword/obj1/bpball",
		"amount5"  : 1,
		"file1"    : "/open/gsword/obj1/bpball",
		"file6"    : "/open/gsword/obj1/bpball",
		"amount4"  : 1,
		"file4"    : "/open/gsword/obj1/bpball",
		"file9"    : "/open/gsword/obj1/bpball",
		"file2"    : "/open/gsword/obj1/bpball",
		"file8"    : "/open/gsword/obj1/bpball",
		"amount3"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10062 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room203.c",
		"south"     : "/open/clan/ou-cloud-club/room/room139.c",
		"north"     : "/open/clan/ou-cloud-club/room/room137.c",
		"out"       : "/open/clan/ou-cloud-club/room/room88",
		"up"        : "/open/clan/ou-cloud-club/room/room119.c",
		"enter"     : "/open/clan/ou-cloud-club/room/room153.c",
		"east"      : "/open/clan/ou-cloud-club/room/room136.c",
		"west"      : "/open/clan/ou-cloud-club/room/room87.c",
	]) );
	set( "long", @LONG
傲雲閤的四樓，這邊的裝飾明顯比前幾樓奢華了許多，因為
這是傲雲山莊的高幹們生活起居的高級樓層，此處是四樓中庭，
為一個寬敞的交誼廳，許多平常深入簡出的高層幹部常會在這邊
露臉，由於這些隱世高手大都身負驚人藝業，因此許多平常難得
一見的稀世珍寶也常會在這裡登場。

往上是------天下無敵劍君十二恨(enter)的藏龍室
北邊是------超凶的波(Perth)的無塵室
南邊是------變態燕(Devil)的樂器室
東邊是------小馬(Bbsboss)和小萱(Vigel)的愛的小窩
西邊是------冰焰(Dracula)的建國千年祭廣場
裡面是------豬圈!!!!!!!!!!!
外面是------小晴(Del)的戰鬥教練場

LONG);
	setup();
	replace_program(ROOM);
}
