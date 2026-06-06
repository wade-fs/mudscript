inherit ROOM;
void create() {
	set( "short", "世間風雲路" );
	set( "object", ([
		"amount1"  : 1,
		"file2"    : "/open/firedancer/npc/eq/r_finger",
		"amount2"  : 1,
		"file1"    : "/open/firedancer/npc/eq/r_leg",
	]) );
	set( "build", 11202 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room164.c",
		"south"     : "/open/clan/13_luck/room/room160",
	]) );
	set( "long", @LONG

　　此路連接著，望月亭及望月樓的必經之路，也把努力犧牲貢獻十
三的幫眾們一一的記錄起來，哲人日已遠，典刑在夙昔。
　　　　　　　古道照顏色　　一一垂丹青 
  ┌───────────────────┐     
  │     十三望月樓----樓層分配圖         │ 
  ├───────────────────┤
  │       第七樓      世間浮華樓         │
  ├───────────────────┤       
  │       第六樓      曾經滄海樓         │
  ├───────────────────┤ 
  │       第五樓      風起雲湧樓         │
  ├───────────────────┤ 
  │       第四樓      齊家安幫樓         │
  ├───────────────────┤ 
  │       第三樓      萬里長征樓         │
  ├───────────────────┤ 
  │       第二樓      壤外定疆樓         │
  ├───────────────────┤ 
  │       第一樓      吉祥天地樓         │    逍遙人間道
  └───────────────────┘ ▁▂▂▁▂▁▂▂▃▂▁▁

LONG);
	setup();
	replace_program(ROOM);
}
