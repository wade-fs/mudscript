inherit ROOM;
void create() {
	set( "short", "貝多芬升C小調第十四號鋼琴奏鳴曲-月光" );
	set( "owner", "ctx" );
	set( "object", ([
		"file10"   : "/obj/gift/lingzhi",
		"file2"    : "/obj/gift/lingzhi",
		"file5"    : "/obj/gift/lingzhi",
		"amount3"  : 1,
		"amount8"  : 1,
		"file6"    : "/obj/gift/bingtang",
		"amount1"  : 1,
		"amount9"  : 1,
		"amount2"  : 1,
		"file4"    : "/obj/gift/lingzhi",
		"amount10" : 1,
		"file9"    : "/obj/gift/lingzhi",
		"amount4"  : 1,
		"amount6"  : 1,
		"file1"    : "/obj/gift/lingzhi",
		"file8"    : "/obj/gift/lingzhi",
		"amount5"  : 1,
		"amount7"  : 1,
		"file3"    : "/obj/gift/lingzhi",
		"file7"    : "/obj/gift/bingtang",
	]) );
	set( "build", 10560 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room583",
	]) );
	set( "long", @LONG
『月光』並非為貝多芬所親題，而是因一位德國批評家兼詩
人雷爾斯達布在文字上的渲染，由出版商附加上去的。這首樂曲
，原先由貝多芬贈與年輕美貌的伯爵千金，她曾為貝多芬的學生
，倆人情投意合而私訂終生，不料為重視門當戶對的伯爵所反對
，深受打擊的貝多芬因而將悲痛情感，傾洩於樂曲中。這首奏鳴
曲寫於1801年。那一年貝多芬在信中承認他對耳疾的恐懼。他在
一封信中還寫道：『我現在正過一種稍微愉快的生活，這種改變
是一個愛我，也為我所愛的可愛的、迷人的女孩帶來的....。不
幸的是，她不是我這個階級的人，而且目前我還不能結婚。』信
中所說的『可愛的、迷人的女孩』就是17歲的伯爵夫人。她是貝
多芬的鋼琴學生，她可能還是作品第18號之一弦樂四重奏中慢板
樂章靈感的來源。

LONG);
	setup();
	replace_program(ROOM);
}
