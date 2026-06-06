inherit ROOM;
void create() {
	set( "short", "二樓southwest" );
	set( "object", ([
		"amount9"  : 3,
		"file2"    : "/open/mon/obj/thousand-nectar",
		"amount4"  : 10,
		"file9"    : "/open/mogi/castle/obj/sspill",
		"amount1"  : 200,
		"file4"    : "/open/mon/obj/thousand-nectar",
		"file1"    : "/open/mon/obj/thousand-nectar",
		"amount2"  : 3,
	]) );
	set( "owner", "djlh" );
	set( "build", 10033 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room699",
		"east"      : "/open/clan/13_luck/room/room700",
	]) );
	set( "long", @LONG

等待  哦最真的愛           も                 も                                
深埋藏在心中春去秋來                   も                も                     
你知道  你愛她  你愛她  你愛她            ╭═╦═╦══╦╮  ╭╦══          
風雨終會過去                      も          ║  ╠═╦╯║  ║╠══    も    
你和她也曾傷心懷疑  卻從未放棄                ╰  ╰　╰  ╰═╯╰══　        
也許你曾哭泣  故事愈美麗愈悲喜  愈教你愛她 ╮     ◢◣◢◣ ║    ║ ╭═══    
她正在期待  你真摯的愛  現在到永遠不會更改 ║              ║    ║ ╠═══    
她正在期待  幸福的未來  任世間滄海都有你在 ║     ◥    ◤ ╰╮╭╯ ║          
直到永遠             も               も   ╰══╯ ◥◤　   ╰╯   ╰═══    

LONG);
	setup();
	replace_program(ROOM);
}
