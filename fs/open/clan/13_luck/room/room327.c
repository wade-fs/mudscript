inherit ROOM;
void create() {
	set( "short", "星空" );
	set( "owner", "woan" );
	set( "object", ([
		"file2"    : "/open/gsword/obj/yu-legging",
		"amount8"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/gsword/obj/yu_cloak",
		"amount4"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/gsword/obj/yubracelet",
		"file6"    : "/open/love/obj/cloth1",
		"amount3"  : 1,
		"file8"    : "/daemon/class/bonze/puty_pullium",
		"file1"    : "/open/love/obj/cloth1",
		"file5"    : "/daemon/class/blademan/obj/shield",
		"amount5"  : 1,
		"amount1"  : 1,
		"file7"    : "/open/gsword/obj/nine_hat",
		"amount7"  : 1,
	]) );
	set( "build", 11574 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room159.c",
		"west"      : "/open/clan/13_luck/room/room328",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    在星空繁華的夜裡，我們手牽著手在一起，  
我要全世界都聽聽，聽我來證明這愛的定義，永
不會熄。從我剛開始認識你，我就想永遠走下去
，我說─讓愛維持下去‧你說─你害怕的事情，  
是愛，像墜落流星。如果可以我會為你，偷一顆
流星，因為世上最愛的人是你，希望你別忘記，  
我們看的第一次流星雨。我說出真心，你靜靜的
聽，你我的心已經互相感應，從今後到永久，
       
          美麗的故事都被放在心中

LONG);
	setup();
	replace_program(ROOM);
}
