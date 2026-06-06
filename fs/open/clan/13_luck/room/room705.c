inherit ROOM;
void create() {
	set( "short", "二樓southeast" );
	set( "owner", "djlh" );
	set( "object", ([
		"amount7"  : 416,
		"file4"    : "/open/fire-hole/obj/b-pill",
		"amount8"  : 18,
		"amount2"  : 300,
		"amount5"  : 100,
		"file7"    : "/open/killer/obj/atman_pill",
		"file6"    : "/open/mogi/castle/obj/sspill",
		"amount1"  : 700,
		"amount6"  : 100,
		"file5"    : "/open/fire-hole/obj/p-pill",
		"amount4"  : 100,
		"file2"    : "/open/fire-hole/obj/r-pill",
		"file3"    : "/open/fire-hole/obj/g-pill",
		"file8"    : "/open/fire-hole/obj/k-pill",
		"amount3"  : 1100,
		"file1"    : "/open/fire-hole/obj/w-pill",
	]) );
	set( "build", 10006 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room700",
		"north"     : "/open/clan/13_luck/room/room698.c",
	]) );
	set( "long", @LONG

      ︴︴︴︴︴                                   ☆張學友 咖啡☆              
    ▃▃▃▃▃▃  太濃了吧 否則怎會苦得說不出話       Fcreper                 
╭─◥◤◥◤◥◤  每次都一個人在自問自答 我們的愛到底還在嗎                     
∣  █◢◣◢◣◢  已經淡了吧 多放些糖也很難有變化                               
∣  ◥◥◤◥◤◤  不如喝完這杯就各自回家 別坐在對面欣賞我的掙扎                 
｜  ◢◢◣◢◣◣  一場失敗的愛情像個笑話 熱的時候心亂如麻                       
╰─◥◥◤◥◤◤  冷了以後看見自己夠傻 人怎麼會如此容易無法自拔                 
    ◥◣◢◣◢◤  一場無味的愛情像個謊話 甜的時候只相信它                       
    ▃▃▃▃▃▃  苦了以後每一句都可怕 人怎麼會如此難以了無牽掛                 
                                                                                

LONG);
	setup();
	replace_program(ROOM);
}
