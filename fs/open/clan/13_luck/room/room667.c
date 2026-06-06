inherit ROOM;
void create() {
	set( "short", "儲藏室" );
	set( "owner", "djlh" );
	set( "object", ([
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"amount3"  : 1,
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/magic-manor/obj/master_snake_head",
		"amount6"  : 1,
		"amount10" : 1,
		"amount9"  : 1,
		"file1"    : "/open/gblade/obj/sa-head",
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"amount5"  : 1,
		"file3"    : "/open/gblade/obj/sa-head",
		"file6"    : "/open/magic-manor/obj/master_snake_head",
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"amount8"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/center/obj/clan-master-head",
		"amount4"  : 1,
	]) );
	set( "build", 10028 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room666",
		"south"     : "/open/clan/13_luck/room/room668.c",
	]) );
	set( "long", @LONG
  
◢～□～■～□～■～□～■能不能不要說--五月天MAYDAY□～■～□～■～□～■～◣  
 昨天的夜裡我夢到彩虹 乘著船 到了盡頭 有一個寶箱上面刻著 青春  打開了 裡面空空  
       ＃第一次 不記得什麼時候 有沒有 握他的手 第一次 不需要想得太多            
 跟著感覺走就不會錯 ＊能不能 不要說 你想要的是什麼 能不能 就愛我 不要問我為什麼 
  十八歲的第一口啤酒 火箭發射 轟隆隆隆   離開了那個擁擠的星球 飛向那 燦爛星空   
     回頭看昨天苦苦的寂寞 突然間 像一個夢 ＊ ※能不能 不要說 其實我不是不懂     
    能不能 就愛我 然後不要太囉嗦   青春的滋味嘗的不夠 沒有瘋狂 怎麼能算活過     
        得到容易 擁有太多 難就難在放手 在那之前 在那之前 我要盡情享受 ＃        
 ＊伊甸園裡偷吃了蘋果 天旋地轉 登陸月球 ※長大換來良心的沉默 所以我要 永遠是現  
 ◥在的我△～▲～△～▲～△～▲～△～▲～△～▲～△～▲～△～▲～ By Forever◤  
  
  
LONG);
	setup();
	replace_program(ROOM);
}
