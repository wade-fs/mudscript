inherit ROOM;
void create() {
	set( "short", "貝多芬F大調第六號交響曲-田園" );
	set( "owner", "ctx" );
	set( "object", ([
		"file4"    : "/obj/gift/shenliwan",
		"file8"    : "/obj/gift/lingzhi",
		"amount8"  : 1,
		"file6"    : "/obj/gift/shenliwan",
		"amount10" : 1,
		"amount5"  : 1,
		"file1"    : "/obj/gift/karwan",
		"file7"    : "/obj/gift/shenliwan",
		"file9"    : "/obj/gift/xisuidan",
		"amount6"  : 1,
		"file2"    : "/obj/gift/lingzhi",
		"file10"   : "/open/gsword/obj1/bbladeball",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/capital/obj/blade2",
		"amount9"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/gblade/obj/sa-head",
		"amount3"  : 1,
	]) );
	set( "item_desc", ([
		"instruction" : @ITEM
第一樂章：抵達鄉村時的愉快氣氛--從容的快板(Allegro ma non troppo)
第二樂章：小河邊的風景--很快的行板(Andante molto mosso)
第三樂章：村民們愉快的聚會--快板(Allegro)
第四樂章：雷雨和暴風--快板(Allegro)
第五樂章：牧歌：暴風雨後的喜悅與感謝--稍快板(Allegretto)
ITEM,
	]) );
	set( "build", 10138 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room583",
	]) );
	set( "long", @LONG
貝多芬說過：「地球上沒有一個人能像我一樣熱愛鄉村，熱
愛自然，甚至一棵樹....。這部作品是描寫人們在田園的喜悅氣
氛中，心中所引發的某些情感....只要一走入田園，我跟我不幸
的耳朵便會豁然開朗....」。「田園」與「命運」同樣於1808年
夏天完成，這兩首曲子被公認是擁有兩種相反而互成對照性格的
樂曲。貝多芬親自為《第六號交響曲》附上「田園」的標題，18
08年12月22日首演，音樂會的節目單上將此曲標以「鄉間生活回
憶」的副題。

       牆上貼了一本樂曲介紹(Instruction)

LONG);
	setup();
	replace_program(ROOM);
}
