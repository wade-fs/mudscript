inherit ROOM;
void create() {
	set( "short", "$BWHT$廢水控制室$NOR$" );
	set( "owner", "kerr" );
	set( "exits", ([
		"up"        : "/open/clan/time-limit/room/room77",
	]) );
	set( "long", @LONG
一陣陣化學藥劑的味道讓近來的人十分不舒服, 這邊有著三,四套的系統交替運
轉處理Fab現場排放的高危險HF廢水, 眼前的採樣人員全身甲級防護衣小心翼翼
作例行性採樣保養, 旁邊還有幾個桶槽, 分別裝滿硫酸,硝酸, 等化學藥劑讓人特別小心,
最特別的是一個漏斗形狀的機械,原來這是HF廢水最後生成的污泥餅
機, 所產生的污泥可以回收當水泥原料, 讓人不禁佩服.

LONG);
	setup();
	replace_program(ROOM);
}
