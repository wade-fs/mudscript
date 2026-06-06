inherit ROOM;
void create() {
	set( "short", "開心之家" );
	set( "object", ([
		"file2"    : "/open/mon/obj/mon-pill",
		"amount7"  : 34,
		"amount1"  : 2,
		"file9"    : "/open/fire-hole/obj/p-pill",
		"file6"    : "/open/capital/obj/book",
		"file7"    : "/open/fire-hole/obj/b-pill",
		"amount2"  : 30,
		"amount4"  : 110,
		"file4"    : "/open/fire-hole/obj/w-pill",
		"file3"    : "/open/fire-hole/obj/r-pill",
		"amount9"  : 95,
		"amount10" : 70,
		"amount6"  : 1,
		"file10"   : "/open/fire-hole/obj/g-pill",
		"file1"    : "/open/ping/obj/poison_pill",
		"amount3"  : 100,
	]) );
	set( "owner", "taa" );
	set( "build", 10782 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room437",
	]) );
	set( "long", @LONG
此地為開心之家，家裡擺滿了各式各樣大大小小的玩具，顧
名思義就是希望來此之人，都能像他一樣開開心心，暫時把煩惱
都拋在腦後，好好地休息一下，無聊之時，亦可把旁邊的玩具拿
來玩耍，以解煩憂之心。
在這亦可參觀開心精心所收藏的兵器---「八色靈器」

           (1)凌微雲扇飄(Lin-cloud-fan)
           (2)雷火彩鳳翔(Fire-color-ribbon)
           (3)幔羅刀無影(Maun-shadow-blade)




LONG);
	setup();
	replace_program(ROOM);
}
