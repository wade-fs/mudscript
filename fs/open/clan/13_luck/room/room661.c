inherit ROOM;
void create() {
	set( "short", "三樓FF" );
	set( "owner", "zmud" );
	set( "object", ([
		"amount3"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"amount9"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-pants",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount5"  : 1,
		"amount1"  : 1,
		"amount8"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount2"  : 1,
		"amount10" : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount7"  : 1,
	]) );
	set( "build", 11145 );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/13_luck/room/room660.c",
		"south"     : "/open/clan/13_luck/room/room709.c",
		"west"      : "/open/clan/13_luck/room/room707.c",
		"east"      : "/open/clan/13_luck/room/room706.c",
		"north"     : "/open/clan/13_luck/room/room708.c",
		"down"      : "/open/clan/13_luck/room/room286",
	]) );
	set( "long", @LONG

★SHINO☆林曉培★SHINO☆林曉培★SHINO☆林曉培★SHINO☆林曉培★SHINO☆林曉培★   
每個人都有些甚麼　我不能不買  ◢■◣ ■  ■ ■■■ ■  ■ ◢■◣                
每個人追捧誰和誰　我不能例外  ◥■◣ ■■■   ■   ■◣■ ■  ■  不知好歹      
否則給誤會我不屬於這個年代    ◥■◤ ■  ■ ■■■ ■◥■ ◥■◤                
怕朋友把我一腳踢開 不知好歹活不到現在 甚麼都看不過眼因為你失敗 明白　不明白     
節目那麼精彩 因為夠奇怪 正經八百活不到現在 你滿臉嚴肅不如回家生小孩 明白不明白  
你也得假裝明白 不然就要說拜拜 每個人亮相的場地　我不能不在 每個人都懂得搞怪　   
我也算不賴 狠下了心腸一天談個新的戀愛 不知道歷史會不會記載 只要變得快　         
不要分好壞 只要吃得開 不要分黑白 不知好歹活不到現在 明白 不明白 正經八百活不到 
明白 不明白 不知好歹活不到現在 走得慢了一拍 就會死的不明不白                    
  
  
LONG);
	setup();
	replace_program(ROOM);
}
