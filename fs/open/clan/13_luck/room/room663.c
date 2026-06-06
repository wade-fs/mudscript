inherit ROOM;
void create() {
	set( "short", "一樓" );
	set( "build", 10202 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room666.c",
		"west"      : "/open/clan/13_luck/room/room664.c",
		"out"       : "/open/clan/13_luck/room/room637.c",
		"east"      : "/open/clan/13_luck/room/room668.c",
		"up"        : "/open/clan/13_luck/room/room662.c",
		"south"     : "/open/clan/13_luck/room/room161",
	]) );
	set( "long", @LONG

── ◥█◤───────── ◥▆◣     ▋ ────── 江美琪 ───────  
▄▄▄▄▄▅▆   ▅▄▃ ◢  ◥██▇◤◥██◤ 如果那時候我沒有愛你 不知道現在  
◥█████◤   ◥█◤██▅ ▃▃▂     ▋        ▅  人會在哪裡 有什麼際遇    
▄▅▆◤█▆▄  ▄  ◢◤◥█ ◥█◤ ◥██◤     █▍ 會不會駐足去聆聽 每一句  
◥██◢◤▍▊   █◤▊◢▋█ ◥█▅ ▃▄█▆   ◢▊   歌詞都是漣漪 想念讓落單  
   ▊   ◣▊◤   █▇▊◥▍█   ▅◣ ◥██◤   ██◣ 人心情變成了 夜裡的詩人  
   ▋ ◢◤◥◣   █  ▊    █  █▎▌◥█ ▋  ◢◤ ◥█▅▄      耳邊一陣風     
   ▍ ◤    ◥◤ ◥█◤◥█◤  ◥█▍   ◥▋◢◤     ◥██◤ 都像愛過的人低語  
─── 等待讓多數人夢裡變成了 寂寞的旅人 閃閃的星光都寫滿了 愛情的詩句 ──── 
  
  
LONG);
	setup();
	replace_program(ROOM);
}
