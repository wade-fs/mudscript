inherit ROOM;
void create() {
	set( "short", "細細品味喔(3)" );
	set( "object", ([
		"amount1"  : 1,
		"amount8"  : 1,
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"amount7"  : 1,
		"amount5"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"amount10" : 1,
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"file2"    : "/open/magic-manor/obj/master_snake_head",
		"amount4"  : 1,
		"amount9"  : 1,
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
	]) );
	set( "owner", "dfyw" );
	set( "build", 10042 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room547",
	]) );
	set( "long", @LONG
愛一個人的時候也是一樣，愛到八分絕對剛剛好。  
　　愛到七八分的時候，思念的酸楚只會有七八分，獨佔的自私只會
有七八分，等待的煎熬會只有七八分，期待和希望也會只有七八分；
剩下兩三分則要用來愛自己。 
　　但是，如果已經愛到了七八分還繼續愛得更多，或者以上情形還
是可以持續保有，但是因為每個人的體質不同，或者愛的方式不同，
也會有許多隨之而來的後遺症，如：愛到忘了自己、給對方造成沉重
的壓力、雙方沒有喘息的空間、過度期望後的失落..等等，完全喪失
了愛情的樂趣。  
所以，飲酒不該醉超過六分，吃飯不該飽超過七分，愛一個人
不該戀超過八分。 
LONG);
	setup();
	replace_program(ROOM);
}
