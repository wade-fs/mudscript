inherit ROOM;
void create() {
	set( "short", "秋心瑀的房間" );
	set( "owner", "iask" );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room53",
	]) );
	set( "object", ([
		"amount5"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/main/obj/dragon-moon",
		"amount1"  : 50,
		"amount2"  : 1,
		"file9"    : "/autoload/swordsman/bloodbook",
		"amount6"  : 33,
		"file1"    : "/open/fire-hole/obj/b-pill",
		"file6"    : "/open/fire-hole/obj/w-pill",
		"amount4"  : 1,
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"file3"    : "/obj/gift/shenliwan",
		"file4"    : "/open/capital/guard/gring",
	]) );
	set( "build", 10449 );
	set( "light_up", 1 );
	set( "long", @LONG
    
    你走進這個房間，頓時一愣，發現這房間的佈置風格異常典雅，
窗戶半掩，淡淡的斜陽由窗櫺透滲進來，輕輕軟軟的暖陽，拂滿了整
個房間。在床邊的書櫃，整齊的排滿了艱澀的古文書，看樣子房間的
主人對古代文學及考究學十分精通，房間擺設佈置整齊乾淨，可以想
見主人的性格想必相當清新脫俗。這即是江湖人稱「任星水無月」，
也是「七御使」之一的 -- 冷薰楓 --的居所。


LONG);
	setup();
	replace_program(ROOM);
}
