inherit ROOM;
void create() {
	set( "short", "和平隔離中心" );
	set( "object", ([
		"file5"    : "/obj/gift/bingtang",
		"amount2"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file7"    : "/obj/gift/lingzhi",
		"file2"    : "/obj/gift/lingzhi",
		"file6"    : "/obj/gift/lingzhi",
		"file3"    : "/obj/gift/lingzhi",
		"amount7"  : 1,
		"file1"    : "/obj/gift/bingtang",
		"file8"    : "/obj/gift/lingzhi",
		"amount10" : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"file10"   : "/obj/gift/lingzhi",
		"amount9"  : 1,
		"file9"    : "/obj/gift/bingtang",
		"file4"    : "/obj/gift/bingtang",
		"amount8"  : 1,
	]) );
	set( "build", 10009 );
	set( "item_desc", ([
		"paper" : @ITEM
1.受輻射照射者請待在此地接受放射科檢查
2.中毒氣者請待在這裡接受全身檢查
3.中病毒細菌者(如SARS)請先隔離14天以上再接受觀察評估
4.本隔離中心不接受精神有問題者
ITEM,
	]) );
	set( "owner", "ctx" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room469",
	]) );
	set( "long", @LONG
劇傳說這邊以前是醫院, 後來因為某些事件後這邊就成為這
附近各研究室實驗時不小心犯錯的研究人員的隔離中心, 當然在
這邊隔離是相當安全的(對沒事的人來說), 所以雖然隔離中心的
的政策常遭人非議,不過因為他的安全性,所以這些日子來也貢獻
良多。

  公告欄上貼了一張隔離說明書(paper)

LONG);
	setup();
	replace_program(ROOM);
}
