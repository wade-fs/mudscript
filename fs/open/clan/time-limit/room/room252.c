inherit ROOM;
void create() {
	set( "short", "星際大冒險3" );
	set( "object", ([
		"amount4"  : 1,
		"amount1"  : 1,
		"file1"    : "/obj/gift/shenliwan",
		"file4"    : "/obj/stone/powder",
	]) );
	set( "build", 10002 );
	set( "owner", "sulamark" );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room253",
	]) );
	set( "long", @LONG
原來男主角就是那個被研究的對象，也是能
回答終極問題的實驗組，那兩隻老鼠在等了幾千萬年之後，問他〔你想問什麼
？〕，他只想知道現在坐在對面的那個女孩愛不愛他，接著又問〔那你的答案
是..〕，我愛那個女孩。老鼠的結論是實驗失敗，要毀掉實驗品，不過某個星
球的人來救了他們。
    其實每個人都在找一個能讓他們問這個問題的對象，然而答案並不重要，
重要的是他到底愛不愛這個會令他產生這種疑問的對象，你們說對嗎？

LONG);
	setup();
	replace_program(ROOM);
}
