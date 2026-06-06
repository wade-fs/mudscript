inherit ROOM;
void create() {
	set( "short", "$HIY$【平南書院】 $CYN$大門$NOR$" );
	set( "owner", "lonsan" );
	set( "light_up", 1 );
	set( "object", ([
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file8"    : "/daemon/class/blademan/obj/shield",
		"amount5"  : 1,
		"amount7"  : 1,
		"amount4"  : 1,
		"file10"   : "/open/tendo/obj/luboot",
		"amount6"  : 1,
		"file2"    : "/open/mogi/castle/obj/lochagem",
		"file6"    : "/open/mogi/dragon/obj/key",
		"amount10" : 1,
		"amount1"  : 1,
		"file7"    : "/open/killer/obj/k_ring",
		"amount9"  : 1,
		"file5"    : "/open/gsword/obj/may_ring",
		"file4"    : "/open/tendo/obj/chaosbelt",
		"amount8"  : 1,
		"file1"    : "/open/poison/obj/feather",
	]) );
	set( "build", 10738 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room140",
		"enter"     : "/open/clan/sky-wu-chi/room/room139",
	]) );
	set( "long", @LONG
在林蔭密佈的小道盡頭，可以看到一間書院獨自佇立在樹海之中，四周一片寧
靜祥和，只有偶爾傳出細細的讀書聲。書院四周用雲南大理石堆砌成白色矮牆，圍
繞著整個書院，而在大門旁邊有一座古色古香的涼亭，似乎經歷過時代的陶冶。走
進大門仔細一瞧，可以發現大門是用高級的紅檜木所製，十分堅固，門上雕刻的是
孔子跟其弟子上課的情景，在門上方有一個黑底金字的牌匾，上面寫著

                *********************************
                *                               *       
                *          $HIY$平 南 書 院$NOR$          *
                *                               *
                *********************************

四個大字，筆法飛揚飄逸，字跡雄渾有力，看得出來是名家手筆。在門口旁邊貼著
一張公告，【進入書院者，請將你隨身武器放在旁邊的架上】。
LONG);
	setup();
	replace_program(ROOM);
}
