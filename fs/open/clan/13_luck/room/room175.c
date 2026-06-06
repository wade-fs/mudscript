inherit ROOM;
void create() {
	set( "short", "後院" );
	set( "outdoors", "/open/clan/13_luck" );
	set( "object", ([
		"amount6"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount8"  : 1,
		"amount3"  : 1,
		"file8"    : "/open/magic-manor/obj/evil-kill-claw",
		"file7"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount4"  : 1,
		"amount5"  : 1,
		"file2"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount9"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount2"  : 1,
		"file5"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount7"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"file10"   : "/open/magic-manor/obj/fire-color-ribbon",
		"file3"    : "/open/magic-manor/obj/hwa-je-icer",
		"file6"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file4"    : "/open/mogi/mountain/obj/frog-pill",
	]) );
	set( "owner", "djlh" );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room668",
		"west"      : "/open/clan/13_luck/room/room161",
	]) );
	set( "light_up", 1 );
	set( "build", 10102 );
	set( "long", @LONG

我也不知 這是怎麼一回事 我的情緒為什麼 忽高又忽低 從來不在意命運＊＊＊＊＊＊    
如何的詭異 直到有你 出現在我的生命　　　　　　　　　　＊＊＊＊＊＊＊＊　＊＊＊  
    ＊　＊＊＊＊　＊　＊＊＊　＊＊　＊＊＊＊＊＊＊  ＊＊＊＊＊　＊＊　＊＊＊    
就像飄在天空　那一顆流星 靜靜等待 千萬年一次的約定 從來不計較結局 ＊＊＊        
  ＊＊＊ 我愛妳 ＊＊＊           短暫放光明 一聲招喚 我會向你飛去 ＊＊＊＊　＊  
＊＊＊ 周俊偉 ＊＊＊                                            ＊＊＊          
等一句 我愛你我愛你我愛你 是我無能為力去抵擋莫名的咒語 只要能有一天 ＊＊        
那怕是輕輕一句 苦也願意 傻也願意 都可以　　　　 　＊＊＊＊＊＊＊＊              
如果愛情 是在找一份美麗 我會用盡 我一生一世的力氣 只是不安定的你 ＊＊＊＊       
不承諾你的心 我會一直 在這裡等你　　＊＊ By  Forever ＊＊＊＊＊＊　＊  　＊     
  
  
LONG);
	setup();
	replace_program(ROOM);
}
