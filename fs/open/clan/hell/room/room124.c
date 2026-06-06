inherit ROOM;
void create() {
	set( "short", "小笨蛋的儲藏室" );
	set( "owner", "acelan" );
	set( "object", ([
		"amount1"  : 28,
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"amount2"  : 1,
		"amount3"  : 10,
		"amount4"  : 3,
		"file2"    : "/obj/gift/xisuidan",
		"file1"    : "/open/ping/obj/poison_pill",
		"file4"    : "/open/mogi/village/obj/f_pill_m",
	]) );
	set( "build", 10299 );
	set( "item_desc", ([
		"script" : @ITEM
session {fs} {140.115.72.117 4000}
act {請輸入您的英文名字} {acelan}
act {請輸入密碼} {xxx}
speedwalk

ticksize 5
tickoff

gag {你坐下來運氣}
alias {f %1} {fight %1;mk}
alias {k %1} {kill %1;mk}
alias {ee} {19 ex 10;ec}
alias {eee} {ex 600;ec 3}
alias {eeee} {ex 1500;ec 5}
alias {rrr} {er;eg;ec;3 eee}
act {似乎內力修為已經遇到了瓶頸} {tickoff}
act {慘遭滅頂,但你也支持不住了。} {boss}
act {^TICK!!!} {ee}
alias {tower} {rn;set wimpy 0;  act {萬蟋椰漱F。} {kill ghost;mk};act {九節屍死了。} {kill ghost;mk};act {鬼死了。} {kill ghost;mk};act {惡魂暴鬼(Ghost)} {k ghost};act {怒馬瘋鬼(Crazy ghost)} {k ghost};act {萬蟋(Ghost)} {k ghost};act {九節屍(Nine ghost)} {k ghost}}

alias {rn} {alias {f %1} {fight %1;rain};alias {k %1} {kill %1;rain}}
alias {manakee} {alias {f %1} {fight %1;mk};alias {k %1} {kill %1;mk}}
alias {weapon} {re;d;8 e;2 n;2 e;pull button;n;enter;n;u;n;e;search;d}

alias {expup} {action {護法死了} {get gold from corpse;k fa}; action {你想殺死誰} {tell kiroro okk!};action {衝出兩位護法} {k fa}}
alias {stopexp} {unact {護法死了};unact {你想殺死誰};unact {衝出兩位護法}}

alias {killer} {re;d;8 e;2 n;2 e;pull button;n;enter}
alias {killerpill} {out;s;2 w;n;get rock;s;w;puton rock;tree;search;3 e;n;enter;4 n;wash;wash;3 s;2 w;give woman herb}
ITEM,
	]) );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room125",
	]) );
	set( "long", @LONG
這裡塞滿了小笨蛋棄置的東西，一個一個的都用蛋殼裝好，整整
齊齊的排列在牆邊，最特別的是在牆上釘了一張紙，上面寫著小笨蛋
用來玩 FS 的 tintin 的 (script) ，這張 script 的內容經常變動
，所以會不定時更新。
LONG);
	setup();
	replace_program(ROOM);
}
