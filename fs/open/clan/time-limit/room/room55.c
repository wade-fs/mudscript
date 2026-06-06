inherit ROOM;
void create() {
	set( "short", "$BRED$二年級$BGRN$黑魔法$BBLU$防禦課$BMAG$教室$NOR$" );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room59",
	]) );
	set( "long", @LONG
二年級生的黑魔法防禦術是由洛哈教授來教導,洛哈教授是個
英俊巫師,曾經贏得五度最佳笑容獎,而他也常常說他的一些英勇
事績,學生們卻不太相信他,認為他只是虛有其表,曾有一次他將綠仙
拿到教室裡放出來,卻造成一場災難,而且也沒有辦法講綠仙捉回去,
從此之後學生們對洛哈教授的印象大打折扣

LONG);
	setup();
	replace_program(ROOM);
}
