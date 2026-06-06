inherit ROOM;
void create() {
	set( "short", "蓋大樓" );
	set( "owner", "panhermes" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room355",
	]) );
	set( "long", @LONG
 想到此地，歲月如灣月 瞬息萬變
青露露的草地 花草樹木千百繁華
白雲漣波襯藍天 暖風颼颼瞋眼簾
業主無情 蓋大樓房間 瞬息萬變
黃滾滾的沙地 水泥鋼筋黃沙塵土
烈陽熾熾於天 燥氣沖天卻寒心
     蓋大樓 蓋大樓
業主歡喜 孩兒憶同年新屋子蓋好 房客如潮水
小王 :「老爺！老家一伙兒，都靠老爺您了。」
LONG);
	setup();
	replace_program(ROOM);
}
