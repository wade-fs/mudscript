inherit ROOM;
void create() {
	set( "short", "貝多芬D小調第九號合唱交響曲" );
	set( "owner", "ctx" );
	set( "item_desc", ([
		"instruction" : @ITEM
第一樂章，不太快的略呈莊嚴的快板，d小調，2/4拍子，奏鳴曲形式。
第二樂章，極活潑的快板，d小調，3/4拍子，龐大的詼諧曲式。
第三樂章，如歌的柔板，降B大調，4/4拍，不規則的變奏曲式。
第四樂章，急板，D大調，4/4拍。在主題"歡樂頌"開始之前，音樂經歷了長時間的器樂部分演奏的痛苦經歷，
      含有對前三個樂章的回憶。
ITEM,
	]) );
	set( "object", ([
		"file9"    : "/obj/gift/unknowdan",
		"amount9"  : 1,
		"amount6"  : 1,
		"file8"    : "/obj/gift/shenliwan",
		"amount5"  : 1,
		"file4"    : "/obj/gift/unknowdan",
		"amount8"  : 1,
		"amount3"  : 1,
		"file5"    : "/obj/gift/xiandan",
		"amount1"  : 1,
		"file6"    : "/obj/gift/shenliwan",
		"file3"    : "/obj/gift/unknowdan",
		"amount7"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"file7"    : "/obj/gift/bingtang",
		"file10"   : "/obj/gift/unknowdan",
		"file2"    : "/obj/gift/unknowdan",
		"file1"    : "/obj/gift/unknowdan",
	]) );
	set( "build", 10035 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room583",
	]) );
	set( "long", @LONG
d小調，第九號交響曲《合唱》，作品大約創作於1819至1824
年間，是貝多芬全部音樂創作生涯的最高峰和總結。作品於1824
年5月7日在維也納首演，即獲得巨大的成功，雷鳴般的掌聲竟達
五次之多。這部交響樂構思廣闊，思想深刻，形象豐富多樣，它
擴大了交響樂的規模和範圍，超出了當時的體裁和規範，變成由
交響樂隊、合唱隊和獨唱、重唱所表演的一部宏偉而充滿哲理性
和英雄性的壯麗頌歌。作者通過這部作品表達了人類尋求自由的
鬥爭意志，並堅信這個鬥爭最後一定以人類的勝利而告終，人類
必將獲得歡樂和團結友愛。這部作品第四樂章的合唱部分是以德
國著名詩人席勒的 歡樂頌 為歌詞而譜曲的，也是本作品中最為
著名的主題。從作品的醞釀到完成，第九交響曲傾盡了貝多芬數
十年的心血，是其音樂生涯的登峰造極之作。

       牆上貼了一本樂曲介紹(Instruction)

LONG);
	setup();
	replace_program(ROOM);
}
