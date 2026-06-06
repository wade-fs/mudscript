inherit ROOM;
void create() {
	set( "short", "$HIR$妖刀$HIG$村正$HIB$ソ塚$NOR$" );
	set( "object", ([
		"file3"    : "/open/magic-manor/obj/soil-ball",
		"file1"    : "/open/magic-manor/obj/wood-ball",
		"amount3"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/obj/water-ball",
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/obj/fire-ball",
	]) );
	set( "build", 10035 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room73",
		"east"      : "/open/clan/sky-wu-chi/room/room73.c",
	]) );
	set( "long", @LONG
鐮倉末期名刀匠岡崎五郎入道正宗弟子村正所作之刀，相傳村正心
術不正，又因正宗不傳他鍊刀的水溫控制秘傳而懷恨在心，就私下盜取
此秘傳來實作，被正宗發現後，一刀砍斷了他的手腕，村正破門之後，
便以打敗正宗所鑄之刀為目標，以此邪惡之心入刀，自此村正成為不詳
的代名詞至於妖刀村正的傳說，源自後來的德川幕府，天文四年，德川
家康的祖父被部下阿部正豐所殺，阿部所持之刀即是村正，天文十四年
，家康的父親松平廣忠被部下岩松八彌斬殺，岩松拿的也是村正之刀，
而家康小時候也因為玩刀不小心而被村正所傷，另外天正七年時，信長
懷疑家康的嫡子信康造反而下達切腹令，當時擔任錯介的天方山城守也
是使用村正刀，當然這些人所用的村正不是同一把，但家康則因此認為
村正是不吉的象徵，家康忌諱村正也廣為人知，因此，後來便有福島正
則，真田幸村等人，利用家康此一心結，與家康為敵時公然佩帶村正刀
，後來德川幕府甚至傳出如果有人公然佩帶村正刀，就是有想背叛德川
家之意，好玩的是，後來在德川御三家的尾張德川家康家發現了不少品
質極佳的村正秘藏！！ 

LONG);
	setup();
	replace_program(ROOM);
}
