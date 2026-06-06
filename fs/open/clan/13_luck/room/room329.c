inherit ROOM;
void create() {
	set( "short", "戀上一個人" );
	set( "owner", "woan" );
	set( "object", ([
		"amount10" : 1,
		"file3"    : "/open/mon/obj/ghost-helmet",
		"amount9"  : 1,
		"amount2"  : 1,
		"amount3"  : 1,
		"file6"    : "/open/mon/obj/ghost-helmet",
		"file5"    : "/open/mon/obj/ghost-cloak",
		"file8"    : "/daemon/class/blademan/obj/ublade",
		"amount7"  : 1,
		"file7"    : "/open/gsword/obj/ring-1",
		"file2"    : "/open/mon/obj/ghost-cloak",
		"amount8"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file9"    : "/open/port/obj/wolf_ring",
		"file4"    : "/open/mon/obj/ghost-legging",
		"file1"    : "/open/mon/obj/ghost-legging",
		"file10"   : "/daemon/class/blademan/obj/nine-blade",
		"amount5"  : 1,
		"amount1"  : 1,
	]) );
	set( "build", 12135 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room328",
		"west"      : "/open/clan/13_luck/room/room330",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
    
    忽然一場陣雨，世界縮為屋簷，你熟悉的側臉，回頭就
在眼前。一分神，丟了手裡煙，墜落了，燃燒的歲月。讓畫
面，再接回從前，省略了，昨天的昨天。後來的你好嗎？有
比較快樂嗎？我應該高興吧，卻又說不上話。雨打濕，你右
邊的肩；淚滑過，我左邊的臉；這就是唯一的關聯。當愛是
，倉促的句點。你曾是，我吻過、我愛過、也傷過、擁有過
、卻錯過的情人。這樣太殘忍。你現在，總是刻意，保持陌
生。你吻過、你愛過、也恨過、擁抱過、卻犯錯的情人。我
不能過問，沒權利再問，他是否對的人。後來的你好嗎？有
比較快樂嗎？我應該高興吧？卻又說不上話。我們是，兩條
平行線，再沒有，任何交叉點，只留下，心酸的感覺。當愛
是，倉促的句點。你吻過、你愛過、也恨過、擁抱過、卻犯
錯的情人。我不能過問，沒權利再問，他是怎樣的人。 
非要等到愛遠走，分兩頭，才知道，多不捨你走，留在午夜
夢回醉，掏了心，傷心對自己說。非要等到愛遠走，分兩頭
，才知道誰都怕寂寞，一直有句話要說，你是我，今生今世
的守候。你吻過、你愛過、也恨過、擁抱過、卻犯錯的情人
。我不能過問，是我先轉身，愛上了，錯的人。

                    ~~~戀上一個人~~~ 

LONG);
	setup();
	replace_program(ROOM);
}
