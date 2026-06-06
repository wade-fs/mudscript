inherit ROOM;
void create() {
	set( "short", "$HIM$紫龍$NOR$區" );
	set( "object", ([
		"file1"    : "/open/fire-hole/obj/p-pill",
		"amount1"  : 45,
	]) );
	set( "owner", "blur" );
	set( "build", 11333 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room27",
	]) );
	set( "long", @LONG

(^^ ....轉承BBB)
紫龍..不是那個常常打死cat的那個聖鬥士星矢...
紫龍精元可以加en magice等級...
ㄜ...就降 :P

吞雲吐霧心得PART3 
(白長)<--軍中最愛...反正你當玩兵後就會愛上它了...但又怕帶不出去..所以許多人把白長放在洋菸的殼子裡,堪稱貍貓換太子現代版
(黃長)<--有點年紀的老頭抽...土味蠻重...有空可試試..
(新樂園)<--老榮民的最愛,俗又大碗...
(520)<--花俏的濾嘴...口感有點老人茶味...但不太耐抽..
(net)<--公賣局推出的新品種...至於味道如何...啊...不就是那樣...

                             (全文完@@?)

LONG);
	setup();
	replace_program(ROOM);
}
