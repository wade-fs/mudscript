inherit ROOM;
void create() {
	set( "short", "天衣無縫" );
	set( "owner", "yaoblade" );
	set( "object", ([
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount2"  : 1,
		"amount6"  : 1,
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount7"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 11543 );
	set( "exits", ([
		"west"      : "/open/clan/nine-sky-dragon/room/room26",
	]) );
	set( "long", @LONG
贊成吧　要的永遠得不到　反對吧　如果你能要得到
對就對　錯就錯　愛絕對要求一個極端 

仔細聽　心中吶喊的聲浪　明明就　遇到完美的對象
一切很明朗　保持風度不如解放 

管誰說出乎意料　我們第一眼就知道
打開了眼界　天生註定已來到請叫好 

一進一退一心一意天衣無縫　兩個苦中作樂
千奇百怪千變萬化天衣無縫　無數樂在其中 

花花世界人海茫茫誰都有苦衷　歌頌愛情聽不進去他們都不懂
百聞不如一見我們還在等什麼　那一舉一動吻合我是你要的 
LONG);
	setup();
	replace_program(ROOM);
}
