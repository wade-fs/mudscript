inherit ROOM;
void create() {
	set( "short", "三樓southeast" );
	set( "owner", "zmud" );
	set( "object", ([
		"file3"    : "/open/capital/obj/4-1",
		"amount1"  : 1,
		"amount2"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/capital/obj/4-1",
		"file2"    : "/open/capital/obj/4-1",
	]) );
	set( "build", 10022 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room706",
		"west"      : "/open/clan/13_luck/room/room709",
	]) );
	set( "long", @LONG

╔══如果那時候我沒有愛你  不知道現在人會在哪裡  有什麼際遇 ══ ═☆ ╗       
║ 遇見了感傷的歌曲  會不會駐足去聆聽  每一句歌詞都是漣漪 ＊  ﹒˙     ╬       
╬如果那時候我沒有失去你  不知道現在我們在哪裡  有什麼心情   ★     。 ╬       
╬  電影裡的美麗劇情  會不會不容易相信  熟悉的對白都心驚         ○    ║       
  ▅▅█▅▅   ▅█▅ ▅█▅        ▂▃▄▅▆by djlh  ▆▅▄▃▂  ☆           
║  ▉ ▄▃     ▅▅  ▄█▄  想念讓落單人心情變成了  夜裡的詩人  。    ＊      
║ ▉  ▎▂▊   ▅▅ ▅▅█▅   ◢ 耳邊一陣風都向愛過的人低語         ‧﹒      
  ◤▊ ▄▄    ▆▅▆ ● █   ◢◤  等待讓多數人夢裡變成了  寂寞的旅人 ║       
║  ▉ ▎◥▄的█▆█  ◥◤ ◢◤◥◣ 閃閃的星光都寫滿了  愛情的詩句    ║       
╚═╬╬﹒．═══ ﹒˙＊﹒ ☆江美琪☆夜的詩人☆ ══ ˙﹒★ ＊══╬═╝       

LONG);
	setup();
	replace_program(ROOM);
}
