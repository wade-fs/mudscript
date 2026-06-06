inherit ROOM;
void create() {
	set( "short", "$HIC$地$HIM$牢$NOR$" );
	set( "exits", ([
		"down"      : "/open/clan/time-limit/room/room62",
		"up"        : "/open/clan/time-limit/room/room9.c",
	]) );
	set( "long", @LONG
這是古代霍格華茲用來禁錮犯校規學生的地牢,現在則被改建成魔藥學教室,
但是仍然保留一部份地牢的模樣,黑板前的大釜咕嚕咕嚕的冒泡,鮮綠色
的液體翻滾著,後方的櫃子上放滿調配魔藥的材料,原本吵鬧的學生們一聽到
開門聲馬上就噤若寒蟬,因為魔藥學教授-'賽佛勒斯-石內卜'準備要上課了,
而他就是有著讓學生不敢吵鬧的威嚴在,讓學生們懼怕不已

LONG);
	setup();
	replace_program(ROOM);
}
