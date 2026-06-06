inherit ROOM;
void create() {
	set( "short", "雙截棍" );
	set( "owner", "panhermes" );
	set( "light_up", 1 );
	set( "object", ([
		"amount9"  : 1,
		"file7"    : "/open/ping/obj/chilin_legging",
		"file4"    : "/daemon/class/blademan/obj/shield",
		"amount8"  : 1,
		"file3"    : "/open/dancer/obj/yuawaist",
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"file8"    : "/daemon/class/fighter/ywgem",
		"amount10" : 1,
		"file5"    : "/open/mogi/castle/obj/seven2-dark-head",
		"amount7"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/wu/npc/obj/armband",
		"amount5"  : 1,
		"amount1"  : 1,
		"file1"    : "/daemon/class/bonze/puty_pullium",
		"amount3"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/ping/obj/gold_hand",
		"file2"    : "/open/killer/weapon/k_head3",
	]) );
	set( "build", 10164 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room278.c",
	]) );
	set( "long", @LONG
岩燒店的煙味瀰漫 隔壁是國術館
店裡面的媽媽三 茶道有三段
教拳腳武術的老闆 練鐵沙掌 耍楊家槍 
硬底子功夫最厲害 還會金鍾罩鐵布杉
他們的兒子我從小就耳濡目染
什麼刀槍根棍棒我都耍的有模有樣
最喜歡的兵器 雙截棍柔中帶剛 想要去河南嵩山學少林跟武當
幹什麼 幹什麼(客) 呼吸吐納心自在
幹什麼 幹什麼(客) 氣沉丹田手心開
幹什麼 幹什麼(客) 日行千里繫沙袋 飛簷走壁莫奇怪 我去去就來
嘿 一個馬步向前一記左鉤拳 右鉤拳
惹毛我的人有危險 一再重演 一跟我不抽的煙 一放好多年 一直在身邊
幹什麼 幹什麼(客) 我打開任督二脈
幹什麼 幹什麼(客) 東亞病夫的招牌
幹什麼 幹什麼(客) 以被我一腳踢開
吭吭哈兮 快使用雙節棍        吭吭哈兮 快使用雙節棍
吭吭哈兮 快使用雙節棍        吭吭哈兮 快使用雙節棍
習武之人切記 仁者無敵      如果我有輕功 飛簷走壁
是誰在練太極 風生水起      為人耿直不屈 一生正氣
LONG);
	setup();
	replace_program(ROOM);
}
