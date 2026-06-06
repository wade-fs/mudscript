inherit ROOM;
void create() {
	set( "short", "$HIG$一年級生$HIY$教室$NOR$" );
	set( "build", 10047 );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room9",
		"east"      : "/open/clan/time-limit/room/room56.c",
		"west"      : "/open/clan/time-limit/room/room38",
		"north"     : "/open/clan/time-limit/room/room59.c",
	]) );
	set( "long", @LONG
走廊上一年級生跑跑跳跳,充滿年輕的活力,圖畫裡的人物熱心的指點不知道
教室位置的新生,有些樓梯飄浮不定,得在一定的時間通行才可以,
還有皮皮鬼來搗蛋,皮皮鬼最喜歡欺侮新生,他最愛看學生驚慌失措的樣子,
學校裡的人都對皮皮鬼沒輒,只有史萊哲林的幽靈-血腥男爵才能真正制的住
皮皮鬼,另外最近常有人提到魔法石,但是卻沒人知道放在何處

LONG);
	setup();
	replace_program(ROOM);
}
