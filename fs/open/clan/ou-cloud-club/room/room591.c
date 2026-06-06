inherit ROOM;
void create() {
	set( "short", "貝多芬C小調第五號交響曲-命運" );
	set( "owner", "ctx" );
	set( "item_desc", ([
		"instruction" : @ITEM
第一樂章：燦爛的快板(Allegro con brio)
第二樂章：稍快的行板(Andante con moto)
第三樂章：詼諧曲：快板(Allegro)
第四樂章：終曲：快板(Allegro)
ITEM,
	]) );
	set( "object", ([
		"file2"    : "/obj/gift/shenliwan",
		"amount5"  : 1,
		"amount7"  : 1,
		"file7"    : "/obj/gift/shenliwan",
		"file8"    : "/obj/gift/shenliwan",
		"file5"    : "/obj/gift/shenliwan",
		"amount4"  : 1,
		"amount10" : 1,
		"file10"   : "/obj/gift/shenliwan",
		"amount6"  : 1,
		"amount2"  : 1,
		"file1"    : "/obj/gift/shenliwan",
		"file6"    : "/obj/gift/shenliwan",
		"amount8"  : 1,
		"file3"    : "/obj/gift/shenliwan",
		"amount3"  : 1,
		"file9"    : "/obj/gift/shenliwan",
		"file4"    : "/obj/gift/shenliwan",
		"amount1"  : 1,
		"amount9"  : 1,
	]) );
	set( "build", 10007 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room583",
	]) );
	set( "long", @LONG
《第五號交響曲》開頭的四個音符，象徵著命運之神前來敲
門的聲音。簡單不過的音符，在他凌厲的安排下，不斷擴張延續
，貫穿全曲，引出了無懈可擊的完美結構，任何人都會從中體驗
到前所未有的震撼與感動。貝多芬說：「我要捏住命運的咽喉，
它絕對無法擊倒我!」這正是命運的最佳註解。

       牆上貼了一本樂曲介紹(Instruction)

LONG);
	setup();
	replace_program(ROOM);
}
