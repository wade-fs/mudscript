inherit ROOM;
void create() {
	set( "short", "對你而言" );
	set( "owner", "yaoblade" );
	set( "object", ([
		"amount10" : 1,
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount7"  : 1,
		"amount1"  : 1,
		"amount8"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount6"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
	]) );
	set( "build", 10157 );
	set( "exits", ([
		"east"      : "/open/clan/nine-sky-dragon/room/room20",
	]) );
	set( "long", @LONG
毀滅的煙　空的房間　和一張你的舊照片　他們說這種畫面叫做懷念 
我計算時間　一疊昨天　那頁數絮亂的從前　找不到你筆跡清楚的抱歉 
對你而言　在你面前　愛沒有所謂虧欠 
誰付出深　誰愛的淺　不過誰走誰先 
對你而言　在你面前　愛沒有所謂虧欠 
所謂熱戀　只是新鮮　我卻聽不進任何人的勸  
南方草原　北方的燕　只交會每年的冬天　他們說這種遙遠年復一年 
而你在身邊　連句永遠　卻從來就不曾蔓延　蔓延在我那一張渴望的臉  
對你而言　在你面前　愛沒有所謂虧欠 
有種字眼　叫做厭倦　總在最後出現 
對你而言　在你面前　愛與恨總會事過境遷 
那些信件　寫的誓言　不過是白紙黑字的表演


LONG);
	setup();
	replace_program(ROOM);
}
